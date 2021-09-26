#include<stdio.h>

int main()
{
	float h, height[10],weight[10],bmi[10];
	int i=0,k=0,j=0,n;
	printf("Enter the number of Persons:\n");
	scanf("%d",&n);
	printf("\nEnter the height & weight of individuals:\n");
	for(i=0;i<n;i++)
	{
		printf("\nPerson %d :\n",i+1);
		printf("Height (in cm): ");
		scanf("%f",&h);
		height[i] = h/100;
		printf("Weight (in kg): ");
		scanf("%f",&weight[i]);
	}
	for(i=0;i<n;i++)
	{
		bmi[i]=weight[i]/(height[i] * height[i]);
	}
	printf("\nThe BMI of the given individuals are :\n");
	for(i=0;i<n;i++)
	{
	printf("\n%d Height-->%.2f\t   Weight-->%.2f\tBMI-->%.2f\t=>",i+1,height[i]*100,weight[i],bmi[i]);
	if(bmi[i]>=35)
		printf("Severely obese");
	else if(bmi[i]>=30)
		printf("Moderately obese");
	else if(bmi[i]>=25)
		printf("Overweight");
	else if(bmi[i]>=18)
		printf("Normal");
	else if(bmi[i]>=15)
		printf("Underweight");
	else
	printf("Severely Underweight");
	
	}
	
	printf("\n");
	return 0;
}
