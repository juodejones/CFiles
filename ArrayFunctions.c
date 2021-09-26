//
//Created by Juode on 27/08/2002
//
//
//Menu driven program to perform array functions
//
//

#include <stdio.h>
int array[20];
int n,i, element;

void create();
void display();
void search();
void insert();
void delete_element();

void main()
{
    int choice, exit = 0;
    printf("  Menu Driven Program to perform array functions");
    printf("\n\t\t\tBy Juode");
    getchar();
    while (exit != 1)
    {
        printf("\n\t1.Create\n\t2.Display\n\t3.Search\n\t4.Insert\n\t5.Delete\n\t6.Exit\nEnter you choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            insert();
            break;
        case 5:
            delete_element();
            break;
        case 6:
            exit = 1;
            break;
        default:
            printf("Invalid choice!");
        }
    }
}

void create()
{
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter the elements of the array : \n");
    for (i = 0; i < n; i++)
    {
		scanf("%d", &array[i]);
    }
}

void display()
{
	printf("Elments of the array : ");
	for (i = 0; i < n; i++)
    {
		printf("\t%d", array[i]);
    }
}

void search()
{
	printf("Enter the element to be searched : ");
	scanf("%d", &element);
	for (i = 0; i < n; ++i)
	{
		if (array[i] == element)
		{
			printf("Element found at %d position.", (i+1));
			break;
		}
	}
	if (i == (n-1))
	{
		printf("Element not found!");
	}
}

void insert()
{
	int pos;
	printf("Enter the element to be inserted : ");
	scanf("%d", &element);
	printf("Enter the poisition of the element : ");
	scanf("%d", &pos);

	for (i = n; i > pos-1; i--)
	{
		array[i] = array[i-1];
	}

	array[pos-1] = element;
	n++;
}

void delete_element()
{
	int pos;
	printf("Enter the element to be deleted : ");
	scanf("%d", &element);

	for (i = 0; i < n; ++i)
		if (array[i] == element)
		{
			pos = i;
			break;
		}
		else
			printf("Element not found");

	for (i = pos; i < n-1; ++i)
		array[i] = array[i+1];

	n--;
}
