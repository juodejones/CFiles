//Created  by Juode

#include<stdio.h>

int main() {

	int size1, size2;
	printf("Enter the number of elements of arr1 : ");
	scanf("%d", &size1);
	int arr1[size1];
	printf("Enter the elements of arr1 : \n");
	for (int i = 0; i < size1; i++)
		scanf("%d", &arr1[i]);
	printf("Enter the number of elements of arr2 : ");
	scanf("%d", &size2);
	int arr2[size2];
	printf("Enter the elements of arr2 : \n");
	for (int i = 0; i < size2; i++)
		scanf("%d", &arr2[i]);
	printf("Common Elements are : ");
	for (int j = 0; j < size1; j++)
		for (int k = 0; k<size2; k++)
			if ( arr1[j] == arr2[k] )
				printf("\t%d", arr1[j]);
	return 0;
}
