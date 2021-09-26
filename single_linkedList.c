//
//Created by Juode on 03/09/2002
//
//Program to understand Linked List
//

void create();
void display();
void insert();
void delete();
void search();
void selection_sort();
// void swap(struct node *a, struct node *b);

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;

};

struct node *Head;
struct node *temp;
struct node *newnode;
int n;

void main()
{
    printf("----Single Linked List----");
    int run = 1;
    while(run)
    {
        int choice;
        printf("\n\t 1-->Create \n\t 2-->Display \n\t 3-->Insert \n\t 4-->Delete \n\t 5-->Search \n\t 6-->Sort \n\t 7-->Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete();
            break;
        case 5:
            search();
            break;
        case 6:
            selection_sort();
            break;
        case 7:
            printf("\nExiting the application....");
            run = 0;
            break;
        default:
            printf("Invalid choice!");
        }
    }
    free(Head);
    free(temp);
    free(newnode);
}

void create()
{
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter element 1 : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    Head = newnode;
    temp = Head;
    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter element %d : ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
}

void display()
{
    printf("\n-----Printing the list-----\n");
    temp = Head;
    while (temp != NULL)
    {
        printf("[ %d : %d ]", temp->data, temp->next);
        temp = temp->next;
    }
}

void insert()
{
    int n;
    printf("Where you want to insert?\n\t1.Beginning\n\t2.Middle\n\t3.End\n");
    scanf("%d", &n);
    newnode = (struct node*)malloc(sizeof(struct node));
    switch (n)
    {
    case 1:
        printf("------Inserting elements in the Beginning-----");
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &newnode->data);
        newnode->next = Head;
        Head = newnode;
        break;
    case 2:
        printf("-----Inserting element in the middle-----");
        printf("\nEnter the position of the element : ");
        scanf("%d", &n);
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &newnode->data);
        int i = 1;
        temp = Head;
        for (int i = 2; i <= n-1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        break;
    case 3 :
        printf("------Inserting elements in the End-----");
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        break;
    default:
        printf("Invalid Choice!");
        break;
    }
    display();
}

void delete()
{
    int n;
    struct node *ptr;
    printf("-----Deleting element in a list-----");
    printf("\nEnter the element to be deleted : ");
    scanf("%d", &n);
    ptr = Head;
    while (ptr != NULL)
    {
        if (ptr->data == n)
        {
            Head = ptr->next;
            break;
        }
        temp = ptr->next;
        if (temp->data == n)
        {
            ptr->next = temp->next;
            break;
        }

        ptr = ptr->next;
    }
    display();
    free(ptr);
}

void search()
{
    int n;
    printf("-----Searching element in a list-----");
    printf("\nEnter the element to be searched : ");
    scanf("%d", &n);
    temp = Head;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            printf("Element found!");
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Element not found!");
    }

}

void selection_sort()
{
    /* int choice;
    struct node *ptr,*min;
    min = Head;
    for (int i = 1; i<n; i++)
    {
        temp = min->next;
        while (temp!= NULL)
        {
            if (temp->data < min->data)
            {
                min = temp;
            }
            temp = temp->next;
        }
        temp = Head;
        while (temp->data != min->data)
        {
            temp = temp->next;
        }
        ptr->data = Head->data;
        Head->data = temp->data;
        temp->data = ptr->data;
        min = Head->next;
    }
    display(); */

    /* int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
  
    if (Head == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = Head;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped); */
    for (int i = 0; i < n; i++)
    {
        temp = Head;
        while(temp->next != NULL)
        {
            if(temp->data > (temp->next)->data)
            {
                int num = temp->data;
                temp->data = (temp->next)->data;
                (temp->next)->data = num;
            }
            temp = temp->next;
        }
    }
    display();
}

void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

//
//Program debugged and ran correctly on 03/09/2002
//
//BY JUODE JONES J