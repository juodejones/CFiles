//
//Created by Juode on 24/09/2021
//
//

#include<stdio.h>
int  queue[3];
int top=-1, last=-1;

void display();
void enqueue();
void dequeue();
void priority();

void main()
{
    int cont = 1;
    top=last=0;
    while (cont)
    {
        int choice;
        printf("\n\t 1-->Enqueue \n\t 2-->Dequeue \n\t 3-->Prior\n\t 4-->Display\n\t 5-->Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            priority();
            break;
        case 4:
            display();
            break;
        case 5:
            cont = 0;
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice!");
        }
    }
}

void display()
{
    printf("\n");
    if (last == top)
    {
        printf("Queue is empty!!");
    }
    else
    {
        for (int i = top; i < last; i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

void enqueue()
{
    if(last >= (sizeof(queue)/sizeof(queue[0])))
    {
        printf("Queue overflow error!!");
    }
    else
    {
        printf("Enter the element to be queued : ");
        scanf("%d",&queue[last++]);
    }
}

void dequeue()
{
    if(last <= top)
    {
        printf("Queue underflow error!!");
    }
    else
    {
        for (int i = top ; i < last; i++)
        {
            queue[i] = queue[i+1];
        }
        last--;
        display();
    }

    
}

void priority()
{
    if(last >= (sizeof(queue)/sizeof(queue[0])))
    {
        printf("Queue overflow error!!");
    }
    else
    {
        for(int i = last ; i >=0; i--  ){
            queue[i] = queue[i - 1];
        }
        printf("Enter prior element : ");
        scanf("%d", &queue[0]);
        last++;
    }

}

//
//Executed with 0 errors
//