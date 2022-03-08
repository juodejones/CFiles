#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff, exp;
    struct node* next;
};

typedef struct node* list;

list create(list);
void display(list);
list add(list, list, list);

int main()
{
    list p1, p2, result;
    p1 = create(p1);
    p2 = create(p2);
    printf("\nPolynomial 1 :  ");
    display(p1);
    printf("\nPolynomial 2 : ");
    display(p2);
    add(p1, p2, result);
    printf("\nSum of polynomials : ");
    display(result);
    return 0;
}

list create(list poly)
{
    int n, i;
    list temp = poly;
    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);
    for (i = 0; i<n; i++)
    {
        temp = (list) malloc(sizeof(struct node));
        temp->next = NULL;
        printf("\nEnter coeff : ");
        scanf("%d", &temp->coeff);
        printf("\nEnter exp : ");
        scanf("%d", &temp->exp);
        temp = temp->next;
    }
    return temp;
}

list add(list p1, list p2, list p3)
{
    list poly1 = p1;
    list poly2 = p2;
    list sum = p3;

    if (poly1 != NULL && poly2 == NULL)
    {
        sum = poly1;
        return sum;
    }
    else if(poly1 == NULL && poly2 != NULL)
    {
        sum = poly2;
        return sum;
    }
    else
    {
        while(poly1->next != NULL && poly2->next != NULL)
        {
            if (sum == NULL)
            {
                sum = (list)malloc(sizeof(struct node));
                sum->next = NULL;
            }
            if(poly1->exp > poly2->exp)
            {
                sum->coeff = poly1->coeff;
                sum->exp = poly1->exp;
                sum = sum->next;
                poly1 = poly1->next;
            }
            else if(poly1->exp < poly2->exp)
            {
                sum->coeff = poly2->coeff;
                sum->exp = poly2->exp;
                sum = sum->next;
                poly2 = poly2->next;
            }
            else if (poly1->exp == poly2->exp)
            {
                sum->coeff = poly1->coeff + poly2->coeff;
                sum->exp = poly1->exp;
                sum = sum->next;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        if (poly1 != NULL)
            sum->next = poly1;
        else if (poly2 != NULL)
            sum->next = poly2;
    }
    return sum;
}

void display(list l)
{
    while (l != NULL)
    {
        printf("%d x^%d", l->coeff, l->exp);
        l = l->next;
    }
}
