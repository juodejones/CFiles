#include <stdio.h>
#include <math.h>

int power(int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
    {
        result = result*a; 
    }
    printf("%d\n", result);
    return result;
    
}

int get_polynomial()
{
    int n, var, result=0;
    printf("\nEnter the degree of the polynomial equation : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = n; i >= 0; i--)
    {
        printf("Enter the coefficient of degree %d : ", i);
        scanf("%d", &arr[i]);
    }
    // printf("Enter the constant term : ");
    // scanf("%d", &arr[n-1]);

    printf("Enter the value of the variable : ");
    scanf("%d", &var);

    for (int i = n; i >= 0; i--)
    {
        result += arr[i]*(power(var, i));
    }
    printf("%d\n", result);

    return result;
}

int main()
{
    int result1, result2, result;
    printf("Enter first polynomial : ");
    result1 = get_polynomial();
    printf("Enter second polynomial : ");
    result2 = get_polynomial();
    printf("Sum of the polynomials = %d", result1+result2);
    return 0;
}