#include <stdio.h>

int main()
{
	int num, temp, digit, sum = 0;
	printf("Enter the number:");
	scanf("%d", &num);

	temp = num;
	while(temp != 0)
	{
		digit = temp % 10;
		sum += digit * digit * digit;
		temp /= 10;
	}

	if(sum == num)
		printf("%d is an Armstrong Number", num);
	else
		printf("%d is not an Armstrong number\n", num);
	return 0;
}

