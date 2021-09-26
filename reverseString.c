#include <stdio.h>
#include <string.h>

int isAlphabet(char x)
{
	return ( (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') );
}

void swap(char *a, char *b)
{
	char *t;
	t = a;
	a = b;
	b = t;
}

void reverse(char str[])
{
	int r = strlen(str) - 1, l = 0;
	while (l < r)
	{
        char temp;
		temp = str[l];
		str[l] = str[r];
		str[r] = temp;
		swap(&str[l], &str[r]);
		l++;
		r--;
	}
}

void main()
{
	char str[15];
	printf("Input string: ");
	gets(str);
	reverse(str);
	printf("Output string: %s\n", str);;
}
