//Created  by Juode

#include <stdio.h>

void main()
{
	int arr[100], n, i, val, p;
	printf("Enter the number of elements in the array : ");
	scanf("%d", &n);
	printf("Enter the elements of the array in ascending order: \n");
	for (i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("The elements of the array before inserting : \n");
	for (i=0;i<n;i++)
		printf("%d\t", arr[i]);
	printf("\n");
	printf("Enter the element to be inserted : ");
	scanf("%d", &val);
	for (i=0;i<n;i++)
		if (arr[i]>val)
		{
			p=i;
			break;
		}
	for(i=n;i>=p;i--)
      arr[i]= arr[i-1];
      arr[p]=val;
      
	printf("The elements of the array after inserting : \n");
	for (i=0;i<=n;i++)
		printf("%d\t", arr[i]);
}
