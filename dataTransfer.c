//
// Created by juode on 29/06/21.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool check_vowel(char);

int main() {

    FILE *file1, *file2;
    file1 = fopen("test1.txt","r");
    file2 = fopen("test2.txt", "w");

    if(file1 == NULL || file2 == NULL)
        printf("Cannot open the file");

    char c = fgetc(file1);
    while (c != EOF) {
        if (!check_vowel(c)) {
            fputc(c, file2);
        }
        c = fgetc(file1);
    }
    fclose(file2);

    file2 = fopen("test2.txt", "r");
    char a = fgetc(file2);
    while (a != EOF) {
        printf("%c", a);
        a = fgetc(file2);
    }

    fclose(file1);
    fclose(file2);
    return 0;

}

bool check_vowel(char c) {
    c = toupper(c);
    if( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' )
        return true;
    return false;
}