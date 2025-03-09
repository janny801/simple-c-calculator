#include <stdio.h>  // Standard input/output library
#include <stdlib.h> // for exit()

double power(double base, double exp) {
    double result = 1.0;
    int i;
    if (exp < 0) {
        for (i = 0; i < -exp; i++) {
            result /= base;
        }
    } else {
        for (i = 0; i < exp; i++) {
            result *= base;
        }
    }
    return result;
}

double operate(double *a, double *b, char op) // Changed char *op to char op
{
    switch (op) // Removed * since op is now passed by value
    {
        case '+': 
            return *a + *b; 
        case '-':
            return *a - *b; 
        case '*': 
        case 'x':
            return *a * *b; 
        case '/': 
            if (*b != 0)
            {
                return *a / *b; 
            }
            else
            {
                printf("Error: Division by 0\n"); 
                exit(EXIT_FAILURE); 
                return 0.0; 
            }
        case '^':
            return power(*a, *b); // Exponentiation using custom power function
        default: 
            printf("Error: Unsupported operator '%c'\n", op); 
            exit(EXIT_FAILURE); 
            return 0.0; 
    }
}

int main()
{
    double num1 = 0.0, num2 = 0.0; // Initialize variables to avoid garbage values
    char operator = '\0'; // Initialize operator to avoid undefined behavior

    printf("Enter the expression: "); 
    
    if (scanf(" %lf %c %lf", &num1, &operator, &num2) != 3) 
    {
        printf("Error: Failed to read input properly.\n");
        return 1;
    }

    double result = operate(&num1, &num2, operator); 
    printf("The result of %.2f %c %.2f is: %.2f\n", num1, operator, num2, result);  
}
