//Created  by Juode

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINBAL 1000

struct Bank_Account
{
    char  no[10];
    char name[20];
    int balance;
};

struct Bank_Account acc;

void main() {
    long int pos1, pos2, pos;
    FILE *fp;
    char *ano, choice;
    int amt;
    int type, flag = 0;
    int bal;

    do {
        fflush(stdin);
        printf("1. Add a New Account Holder\n");
        printf("2. Display\n");
        printf("3. Deposit or Withdraw\n");
        printf("4. Less than the Minimum Balance\n");
        printf("5. Stop\n");
        printf("Enter your choice : ");
        choice = getchar();
        getchar();
        switch (choice) {
            case '1' :
                fflush(stdin);
                fp = fopen("acc.dat", "a");
                printf("\nEnter the Account Number :");
                gets(acc.no);
                printf("Enter the Account Holder Name : ");
                gets(acc.name);
                printf("Enter the Initial Amount to deposit : ");
                scanf("%d", &acc.balance);
                fseek(fp, 0, 2);
                fwrite(&acc, sizeof(acc), 1, fp);
                fclose(fp);
                break;
            case '2' :
                fp = fopen("acc.dat", "r");
                if (fp == NULL)
                    printf("\nFile is Empty");
                else {
                    printf("\nA/c Number\tA/c Holder Name \tBalance\n");
                    while (fread(&acc, sizeof(acc), 1, fp) == 1)
                        printf("%s\t\t%s\t\t\t%d\n", acc.no, acc.name, acc.balance);
                    fclose(fp);
                }
                break;
            case '3':
                fflush(stdin);
                flag = 0;
                fp = fopen("acc.dat", "r+");
                printf("\nEnter the Account Number :");
                gets(ano);

                for (pos1 = ftell(fp);
                     fread(&acc, sizeof(acc), 1, fp) == 1;
                     pos1 = ftell(fp)) {
                    if (strcmp(acc.no, ano) == 0) {
                        printf("\nEnter 1 for deposit & 2 for withdraw : ");
                        scanf("%d", &type);
                        printf("\nYour	Current	Balance	is	:%d", acc.balance);
                        printf("\nEnter the Amount to transact : ");
                        fflush(stdin);
                        scanf("%d", &amt);
                        if (type == 1)
                            bal = acc.balance + amt;
                        else {
                            bal = acc.balance - amt;
                            if (bal < 0) {
                                printf("\nRs.%d	Not	available	in	your A/c\n", amt);
                                flag = 2;
                                break;
                            }
                        }
                        flag++;
                        break;
                    }
                }
                if (flag == 1) {
                    pos2 = ftell(fp);
                    pos = pos2 - pos1;
                    fseek(fp, -pos, 1);
                    printf("%d", bal);
                    acc.balance = bal;
                    fwrite(&acc, sizeof(acc), 1, fp);
                } else if (flag == 0)
                    printf("\nA/c Number Not exits... Check it again");
                fclose(fp);
                break;
            case '4' :
                fp = fopen("acc.dat", "r");
                flag = 0;
                while (fread(&acc, sizeof(acc), 1, fp) == 1) {
                    bal = acc.balance;
                    if (bal < MINBAL)
                        flag++;
                }
                printf("\nLess than the Minimum Balance : %d", flag);
                fclose(fp);
                break;
            case '5':
                fclose(fp);
                exit(0);
        }
        printf("\nDone.\n");
    } while (choice != '5');
}