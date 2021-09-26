//
// Created by juode on 13/08/21.
//

#include <stdio.h>

int main()
{
    char str[50];
    scanf("%s", str);
    for(int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if(ch >= 'a' && ch <= 'z') {
            printf("%c", 'A'+(ch-'a'));
        } else {
            printf("%c", 'a'+(ch-'A'));
        }
    }
    return 0;
}
