#include <stdio.h>  // Standard input/output library
#include <stdlib.h> //for exit()


/*
int add(int *a , int *b)
{
    return *a + *b; 
}

*/

// Function to calculate exponentiation without using math.h
double power(double base, double exp) 
{
    // Handle special cases
    if (base == 0 && exp <= 0) 
    {
        printf("error: 0 cannot be raised to a non-positive power\n");
        exit(EXIT_FAILURE);
    }
    if (exp == 0) return 1.0; // Any number to the power of 0 is 1

    double result = 1.0;
    int i;

    // If exponent is negative, take the reciprocal after computing the positive exponent
    int is_negative = (exp < 0);
    double positive_exp = (is_negative) ? -exp : exp;

    // Exponentiation using iterative multiplication for integer part
    for (i = 0; i < (int)positive_exp; i++) 
    {
        result *= base;
    }

    // Handle fractional exponent approximation using simple Taylor expansion for e^(x ln base)
    double fractional_part = positive_exp - (int)positive_exp; // Extract decimal part of exponent
    double term = fractional_part * (base - 1); // Approximate ln(base) as (base - 1)
    double frac_result = 1.0 + term / 1 + (term * term) / 2 + (term * term * term) / 6; // Taylor expansion

    result *= frac_result; // Multiply integer exponentiation with fractional approximation

    return (is_negative) ? (1.0 / result) : result;
}


double operate(double *a, double *b, char op) // Changed char *op to char op
{
    //function to calculate vals 
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
            //check if division by 0 
            if (*b != 0)
            {
                return *a / *b; 
            }
            else
            {
                printf("error: division by 0\n"); 
                exit(EXIT_FAILURE); 
                return 0.0; 
                
            }
        case '^': // Exponentiation case
            return power(*a, *b); 
        default: 
            printf("you used %c which is not supported\n", op); // Removed * since op is now a value
            exit(EXIT_FAILURE); 
            return 0.0; 
            
    }
}





int main()
{
    double num1 = 0.0, num2 = 0.0; // Initialize variables to avoid garbage values
    char operator = '\0'; // Initialize operator to avoid undefined behavior

    printf("enter the expression: "); 
    
    // Check if scanf reads input correctly
    if (scanf(" %lf %c %lf", &num1, &operator, &num2) != 3) 
    {
        printf("Error: Failed to read input properly.\n");
        return 1;
    }

    /* Debugging output to check values
    
    printf("Debug: num1 = %.2f, operator = '%c' (ASCII: %d), num2 = %.2f\n", num1, operator, operator, num2);
    */



    double result = operate(&num1, &num2, operator); // Passed operator by value

    printf("the result of %.2f %c %.2f is: %.2f\n", num1, operator, num2, result);  

}
