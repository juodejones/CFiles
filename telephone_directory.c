#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Phonebook {
    char name[20];
    long int phonenumber;
}phone;

void add(phone *);
void del(phone *);
void print(phone *);
void search(phone *);

int counter = 0;
FILE *pRead, *pWrite;

int main() {

    phone *phonebook = (phone*) malloc(sizeof(phone)*100);
    int iSelection = 0;

    if (phonebook == NULL) {
        printf("Out of memory. Can't proceed further.");
    } else {
        do {
            printf("\n\t\t\tPhonebook Menu");
            printf("\n\t(1)\tAdd Friend");
            printf("\n\t(2)\tDelete Friend");
            printf("\n\t(3)\tDisplay Phonebook Entries");
            printf("\n\t(4)\tSearch for Phone Number");
            printf("\n\t(5)\tExit Phonebook");
            printf("\nWhat would you like to do? ");
            scanf("%d", &iSelection);
            getchar();
            switch (iSelection) {
                case 1:
                    add(phonebook);
                    break;
                case 2:
                    del(phonebook);
                    break;
                case 3:
                    print(phonebook);
                    break;
                case 4:
                    search(phonebook);
                    break;
                case 5:
                    printf("Exiting phonebook directory...");
                    exit(1);
                default:
                    printf("Exiting phonebook directory...");
            }
        } while (iSelection <= 4);
    }
    return 0;
}

void add(phone *phonebook) {
    pWrite = fopen("phonebook.dat", "a");

    if(pWrite == NULL){
        perror("The following error acquired, ");
        exit(EXIT_FAILURE);
    } else {
        counter++;
        realloc(phonebook, sizeof(phone)*100);
        printf("Name : ");
        scanf("%[^\n]s", phonebook[counter-1].name);
        getchar();
        printf("Phone number : ");
        scanf("%ld", &phonebook[counter-1].phonenumber);
        fprintf(pWrite, "%s\t%ld\n", phonebook[counter-1].name, phonebook[counter-1].phonenumber);
        printf("Successfully added the contact!");
    }
    fclose(pWrite);
}

void del(phone *phonebook) {

    char name[20];
    printf("Contact name : ");
    scanf("%[^\n]s", name);
    for (int x = 0; x < counter; ++x) {
        if(strcmp(name, phonebook[x].name) == 0) {
            for (int i = x; i < counter; i++) {
                strcpy(phonebook[i].name, phonebook[i+1].name);
                phonebook[i].phonenumber = phonebook[i+1].phonenumber;
            }
            printf("Contact deleted from the phonebook.");
            counter--;
        } else {
            printf("Contact not found.");
        }
    }
}

void print(phone *phonebook) {

    pRead = fopen("phonebook.dat", "r");
    if(pRead == NULL) {
        perror("The following error acquired, ");
        exit(EXIT_FAILURE);
    } else {
        printf("Phonebook entries, \n");
        for (int i = 0; i < counter; ++i) {
            printf("\t%s -> %ld\n", phonebook[i].name, phonebook[i].phonenumber);
        }
    }
    fclose(pRead);
}

void search(phone *phonebook) {

    char name[20];
    printf("Type the name : ");
    scanf("%[^\n]s", name);

    for (int i = 0; i < counter; ++i) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Contact found.");
            printf("%s -> %ld", phonebook[i].name, phonebook[i].phonenumber);
        }
    }
}
