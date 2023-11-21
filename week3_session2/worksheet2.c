//6

#include <stdio.h>

float operation(float a, float b , char c)
{
    float answer;
    
    switch (c)
    {
        case '+':
            answer = a + b ;
            break;
        case '-':
            answer = a - b;
            break;
        case '*':
            answer = a * b;
            break;
        case'/':
            answer = a / b;
            break;  
        default :printf("Invalid operation");
            break;      
    }
    return answer;
}

int main()
{
    float a;
    float b; 
    char c;
    float answer;

    printf("Enter your first number: \n");
    scanf("%f", &a);

    printf("Enter your second number: \n");
    scanf("%f", &b);

    printf("Enter your operand: \n");
    scanf("%c", &c);

    answer = operation(float a, float b, char c);

    printf("The result of %.2f %c %.2f = %.2f", a,c,b,answer);

    return 0;
}
