//Created  by Juode

#include <stdio.h>
int aboveavg(int a[],int n,int avg);
int avgheight(int a[],int n);

int aboveavg(int a[],int n,int avg) {
 	int i=0,c=0;
 	for(i=0;i<n;i++) {
 		if(a[i]>avg)
 			c++;
 	}
 	return c;
}

int avgheight(int a[],int n) {
 	int total=0,i=0,mean;
 	for(i=0;i<n;i++) {
 		total=total+a[i];
 	}
	mean=total/n;
 	return mean;
}

void main() {
	
	int a[5],avg,count,n,i=0;
	printf("Enter the no of persons\n");
	scanf("%d",&n);
	printf("Enter the height of %d persons in cm\n",n);
 	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	avg=avgheight(a,n);
	printf("The average height of %d persons is:%d\n",n,avg);
 	count=aboveavg(a,n,avg);
	printf("The no of persons above the avg height, %d are:%d\n",avg,count);
	
}
