//
//Created by Juode on 07/09/2002
//
//Program to understand Double Linked List
//

#include <stdio.h>
#include <stdlib.h>

int n;

void create();
void display();
void insert();
void delete();
void search();

struct node
{
    int data;
    struct node *previous;
    struct node *next;
};

struct node *Head;
struct node *temp;
struct node *newnode;
struct node *Last;

void main()
{
    printf("-----Double Linked List-----");
    int run = 1;
    while(run)
    {
        int choice;
        printf("\n\t 1-->Create \n\t 2-->Display \n\t 3-->Insert \n\t 4-->Delete \n\t 5-->Search \n\t 6-->Exit\nEnter your choice : ");
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
    free(Last);
}

void create()
{
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter element 1 : ");
    scanf("%d", &newnode->data);
    newnode->previous = NULL;
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
        newnode->previous = temp;
        temp = newnode;
    }
    Head->previous = temp;
    temp->next = Head;
    Last = temp;
    Head->previous = Last;
}

void display()
{
    int i = 0, a;
//    printf("%d", sizeof(struct node));
    printf("\n-----Printing the list-----");
    printf("\n\t1.Clockwise\n\t2.Anticlockwise\nEnter your choice : ");
    scanf("%d", &a);
    if (a == 1)
    {
        temp = Head;  
        while (i < n)
        {
            printf("[ %d : %d ]", temp->data, temp->next);       
            temp = temp->next;
            i++;
        }
    }
    else if ( a == 2)
    {
        temp = Last;  
        while (i < n)
        {
            printf("[ %d : %d ]", temp->data, temp->next);       
            temp = temp->previous;
            i++;
        }
    } else
    {
        printf("Invalid choice!");
    }
}

void insert()
{
    int a;
    printf("Where you want to insert?\n\t1.Beginning\n\t2.Middle\n\t3.End\n");
    scanf("%d", &a);
    newnode = (struct node*)malloc(sizeof(struct node));
    n++;
    switch (a)
    {
    case 1:
        printf("------Inserting elements in the Beginning-----");
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &newnode->data);
        newnode->next = Head;
        newnode->previous = Last;
        Head->previous = newnode;
        Last->next = newnode;
        Head = newnode;
        break;
    case 2:
        printf("-----Inserting element in the middle-----");
        printf("\nEnter the position of the element : ");
        scanf("%d", &a);
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &newnode->data);
        int i = 1;
        temp = Head;
        for (int i = 2; i <= a-1; i++)
        {
            temp = temp->next;
        }
        newnode->previous = temp->previous;
        newnode->next = temp->next;
        temp->next = newnode;
        break;
    case 3 :
        printf("------Inserting elements in the End-----");
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &newnode->data);
        newnode->next = Head;
        newnode->previous = Last;
        Last->next = newnode;
        Last = newnode;
        Head->previous = Last;
        break;
    default:
        printf("Invalid Choice!");
        break;
    }
    display();
}

void delete()
{
    int a, i = 0;
    printf("-----Deleting element in a list-----");
    printf("\nEnter the element to be deleted : ");
    scanf("%d", &a);
    temp = Head;
    n--;
    while (i < n)
    {
        if (temp->data == a)
        {
            if (temp->previous == NULL)
            {
                Head = temp->next;
                Head->previous = NULL;
                break;
            }
            else
            {
            (temp->previous)->next = temp->next;
            (temp->next)->previous = temp->previous;
            break;
            }
        }
        temp = temp->next;
        i++;    
    }
    free(temp);
    display();
}

void search()
{
    int a, i = 0;
    printf("-----Searching element in a list-----");
    printf("\nEnter the element to be searched : ");
    scanf("%d", &a);
    temp = Head; 
    while (i < n)
    {
        if (temp->data == a)
        {
            printf("Element found!");
            break;
        }
        temp = temp->next;
        i++;
    }
    if (i == n)
    {
        printf("Element not found!");
    }
    
}

//
//Program debugged and executed correctly on 0/09/2002
//
//BY JUODE JONES J