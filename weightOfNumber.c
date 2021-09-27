//Created  by Juode

#include <stdio.h>
#include <math.h>

int prime(int n) {
	int flag = 1;
	
	for (int i = 2; i <= n; i++) {
	if (n%i == 0)
		flag = 0;
		
	if(flag)
		return 1;
	else 
		return 0;
	}
}

int cube(int n) {
	
	int flag = 0;
	for ( int i=1; i <= n; i++) {
		if((i*i*i)==n)
 		{
 			flag=1;
 			break;
 		}
 	}
 	return flag;
}

int getWeight(int n)
{
 	int w=0;
 	if(cube(n))
 		w+=5;
 	if(n%4==0 && n%6==0)
 		w+=4;
 	if(prime(n))
 			w+=3;
 	return w;
} 

void main() {
	int nums[15], ws[15];
 	int i,j,t,n;

	printf("Enter the number of numbers: ");
	scanf("%d",&n);
	printf("\nEnter the numbers:\n");
 	for(i=0;i<n;i++)
		scanf("%d",&nums[i]);
 	for(i=0;i<n;i++)
 		ws[i]=getWeight(nums[i]);
	printf("\nBefore sorting:\n");
 	for(i=0;i<n;i++)
		printf("<%d,%d>\t",nums[i],ws[i]);
 	for(i=0;i<n;i++)
 		for(j=0;j<n-i-1;j++)
	if(ws[j]>ws[j+1]) {
 		t=ws[j+1];
 		ws[j+1]=ws[j];
 		ws[j]=t;
 		t=nums[j+1];
 		nums[j+1]=nums[j];
 		nums[j]=t;
 	}
	printf("\nSorted:\n");
	for(i=0;i<n;i++)
	printf("<%d,%d>\t",nums[i],ws[i]);
}
