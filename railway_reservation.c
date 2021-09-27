//Created  by Juode

#include<stdio.h>
#include <stdlib.h>

int first=5,second=5,third=5;
struct node
{
    int phoneno;
    char name[100];
    char address[100];
    int booked;
}s[15];

void booking()
{
    int class, seat = 0, no;
    printf("\n1.First	class\n2.Second	class\n3.Third class\n");
    scanf("%d", &class);
    switch (class) {
        case 1:
            seat = 0;
            first--;
            break;
        case 2:
            seat = 5;
            second--;
            break;
        case 3:
            seat = 10;
            third--;
            break;
    }
    printf("Seat Number only 1-5:\n");
    scanf("%d",&no);
    seat += no;
    if (s[seat].booked == 0) {
        printf("Enter your details");
        printf("\nName:");
        scanf("%s",s[seat].name);
        printf("Phonenumber:");
        scanf("%d",&s[seat].phoneno);
        printf("Address:");
        scanf("%s",s[seat].address);
        s[seat].booked = 1;
    } else {
        printf("Seat is already booked.\n");
    }
}

void availability()
{
    int c;
    printf("Availability cheking");
    printf("\n1.First	class\n2.Second	class\n3.Third class\n");
    printf("Enter the option : "); scanf("%d",&c);
    switch(c)
    {
        case 1:
            if(first>0)
            {
                printf("Seat available\n");
//                first--;
            }
            else
                printf("Seat not available");
                break;
        case 2:
            if(second>0)
            {
                printf("Seat available\n");
//                second--;
            }
            else
                printf("Seat not available");
            break;
        case 3:
            if(third>0)
            {
                printf("Seat available\n");
//                third--;
            }
            else
                printf("Seat not available");
            break;
        default:
            printf("Invalid Choice");
    }
}
void cancel()
{
    int c, seat = 0, no;
    printf("Cancel\n");
    printf("Which class you want to cancel?");
    printf("\n1.First	class\n2.Second	class\n3.Third class\n");
    printf("Enter the option");
    scanf("%d",&c);
    printf("Enter the seat number : ");
    scanf("%d",&no);
    switch(c)
    {
        case 1:
            seat = 0;
            first++; break;
        case 2:
            seat = 5;
            second++; break;
        case 3:
            seat = 10;
            third++; break;
        default:
            break;
    }
    seat += no;
    s[seat].booked = 0;
    printf("Ticket is canceled\n");
}
void chart()
{
    int	c, i=1;
    printf("\nNo\tName\tClass\tNumber\n");
    for(c=0;c<=15;c++)
    {
        if(s[c].booked == 1) {
            if (c > 5 && c <= 10) {
                printf("%d \t%s\tSecond\t%d\n",i,s[c].name,(c-5));
            } else if ( c > 10 && c <= 15) {
                printf("%d \t%s\tThird\t%d\n",i,s[c].name,(c-10));
            } else {
                printf("%d \t%s\tFirst\t%d\n",i,s[c].name,c);
            }
            i++;
        }
    }
}
main()
{
    int n;
    printf("Welcome to railway ticket reservation\n");
    while(1)
    {
        printf("1.Booking\n2.Availabilitycheking\n3.Cancel\n4.Chart\n5. Exit\nEnter your option:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                booking(); break;
            case 2:
                availability(); break;
            case 3:
                cancel(); break;
            case 4:
                chart(); break;
            case 5:
                printf("\nThank you visit again!");
                getchar();
                exit(0);
            default:
                break;
        }
    }
}

