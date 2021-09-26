//
// Created by juode on 07/07/21.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void myFunc(char *str[], int op);
void replace(char string[], char old[], char new[]);

int main() {

    int choice;
    char string[100], old[20], new[20];

    printf("Enter a string : ");
    scanf("%[^\n]s", string);
    printf("String is : %s\n", string);


    printf("Options are, \n1 -> Find the total number of words"
           "\n2 -> Capitalize the first letter of each word"
           "\n3 -> Replace a word"
           "\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            myFunc(&string, 0);
            break;
        case 2:
            myFunc(&string, 1);
            printf("%s", string);
            break;
        case 3:
            printf("Enter the word to be replaced : ");
            scanf("%s", old);
            printf("Enter the old word : ");
            scanf("%s", new);
            replace(string, old, new);
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}

void myFunc(char *str[], int op)
{
    int wc = 1; char old;
    if ( str[0] != '\0') {
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
                if (op == 0) {
                    wc++;
                } else if (op == 1){
                    old = toupper(str[i + 1]);
                    str[i + 1] = old;
                }
            }
        }
        op==0 ? printf("Number of words in the sentence is : %d", wc) : printf("Capitalized...");
    }
    else
        printf("String is empty!");
}

void replace(char string[], char old[], char new[]) {

    char *p, str[50];

    p = strstr(string, old);
    if(p) {
        strncpy(str, string, p - string);
        str[p-string] = 0;
        sprintf(str + (p-string), "%s%s", new, p + strlen(old));
        string[0] = 0;
        strcpy(string, str);
        printf("%s", string);
    } else {
        printf("Word not found");
    }
}

