//
//Created by Juode on 04/09/2002
//
//Program to understand Double Linked List
//

void create();
void display();
void insert();
void delete();
void search();

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *previous;
    struct node *next;
};

struct node *Head;
struct node *temp;
struct node *newnode;

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
}

void create()
{
    int n;
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
}

void display()
{
//    printf("%d", sizeof(struct node));
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
        Head->previous = newnode;
        newnode->next = Head;
        newnode->previous = NULL;
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
        newnode->previous = temp->previous;
        newnode->next = temp->next;
        temp->next = newnode;
        display();
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
        newnode->previous = temp;
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
    printf("-----Deleting element in a list-----");
    printf("\nEnter the element to be deleted : ");
    scanf("%d", &n);
    temp = Head;
    while (temp != NULL)
    {
        if (temp->data == n)
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
    }
    free(temp);
    display();
}

void search()
{
    int n;
    printf("-----Searching element in a list-----");
    printf("\nEnter the element to be searched : ");
    scanf("%d", &n); 
    temp = Head->next;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }  
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            printf("Element found!");
            break;
        }
        temp = temp->previous;
    }
    if (temp == NULL)
    {
        printf("Element not found!");
    }
    
}

//
//Program debugged and executed correctly on 04/09/2002
//
//BY JUODE JONES J