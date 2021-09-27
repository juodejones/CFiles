//Created  by Juode

#include <stdio.h>

void main()
{
    int num, rev = 0, n, temp;
    printf("Enter a number : ");
    scanf("%d", &num);
    temp = num;
    while(temp > 0)
    {
        n = temp%10;
        rev = (rev*10) + n;
        temp = temp/10;
    }
    if(rev == num)
    {
        printf("Palindrome");
    } else
    {
        printf("Not palindrome");
    }
}
