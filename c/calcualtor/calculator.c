#include <stab.h>
#include <stdio.h>


int main() {

    char operator;
    double first, second;
    
    printf("Enter an operator (+,-,/,*)");
    scanf("%c", &operator);

    
    printf("Enter two opeator");
    scanf("%lf %lf", &first, &second);


    switch (operator)
    {
    case '+':
        printf("%.1f + %1.f = %.1f\n", first, second, first + second);
        break;
    case '-':
        printf("%.1f + %1.f = %.1f\n", first, second, first  - second);
        break;
    case '/':
        printf("%.1f + %1.f = %.1f\n", first, second, first / second);
        break;
    case '*':
        printf("%.1f + %1.f = %.1f\n", first, second, first * second);
        break;

    default:
        printf("invlaid oprator \n");
    }

    return 0; 
}