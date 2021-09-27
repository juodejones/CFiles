//Created  by Juode

#include <stdio.h>
#include<math.h>
int main() {
    char operator;
    int result = 1;
    int first, second, power = 1;
    printf("+ -> Addition,\n- -> Subtraction,\n* -> Multiplication,\n/ -> Division,\n! -> Factorial,\n%% -> Modulus,\n^ -> Exponent\nEnter an operator: ");
    scanf("%c", &operator);
    printf("Enter two operands: \n");
    scanf("%d %d", &first, &second);

    switch (operator) {
    case '+':
        printf("%d + %d = %d\n", first, second, first + second);
        break;
    case '-':
        printf("%d - %d = %d\n", first, second, first - second);
        break;
    case '*':
        printf("%d * %d = %d\n", first, second, first * second);
        break;
    case '/':
        printf("%d / %d = %d\n", first, second, first / second);
        break;
    case '!':
        for (int i = 1; i <= first; i++)
        {
            result *= i;
        }
        printf("%d! = %d\n", first, result);
        result = 1;
        for (int i = 1; i <= second; i++)
        {
            result *= i;
        }
        printf("%d! = %d\n", second, result);
        break;
    case '%':
        printf("%d %% %d = %d\n", first, second, first % second);
        break;
    case '^':
        for (int i = 0; i < second; i++)
        {
            power *= first;
        }
        
        printf("%d ^%d = %d\n", first, second, power);
        break;    
    default:
        printf("Error! operator is not correct\n");
    }

    return 0;
}