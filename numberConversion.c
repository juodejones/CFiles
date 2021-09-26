#include<stdio.h>
void bin(int n);
void hex(int n);
void oct(int n);
void main()
{
	int n;
	printf("Enter the number --> ");
	scanf("%d",&n);
	bin(n);
	hex(n);
	oct(n);
	printf("\n");
}

void bin(int n)
{
	int B[50],i=0,len;
	while(n>0)
	{
		B[i]=n%2;
		n=n/2;
		i++;
	}
	len=i;
	printf("The binary equivalent of given number %d is --> ",n);
	for(i=0;i<len;i++)
	{
		printf("%d",B[len-i-1]);
	}
}

void hex(int n)
{
	int i=0,len,rem;
	char H[50];
	while(n>0)
	{
		rem=n%16;
		if(rem>9)
		{
			H[i]=55+rem;
		}
		else
		{
			H[i]=48+rem;
		}
		n=n/16;
		i++;
	}
	len=i;
	printf("\nThe hexadecimal equivalent of given number %d is --> ",n);
	for(i=0;i<len;i++)
		printf("%c",H[len-1-i]);
}

void oct(int n)
{
	int O[50],i=0,len;
	while(n>0)
	{
		O[i]=n%8;
		n=n/8;
		i++;
	}
	len=i;
	printf("\nThe ocatal equivalent of the given number %d is --> ",n);
	for(i=0;i<len;i++)
	{
		printf("%d",O[len-1-i]);
	}
}
