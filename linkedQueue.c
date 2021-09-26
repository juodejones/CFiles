#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*Head;
int n;

void enque()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = newnode;
    temp = temp->next;
}

void display()
{
    printf("\n");
    temp = Head;
    for(int i = 0 ; i < n; i++)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void deque()
{
    if (Head != NULL)
    {
        temp = Head;
        Head=temp->next;
        temp = Head;
        n--;
    } else {
        printf("Underflow!\t Queue is empty.");
    }

}
void priority()
{
    temp = Head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter element to be attache at most priority:  ");
    scanf("%d",&newnode->data);
    newnode->next = temp;
    Head = newnode;
    n++;
}

void main()
{
}
