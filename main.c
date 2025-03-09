#include <stdio.h>  // Standard input/output library
#include <stdlib.h> //for exit()


/*
int add(int *a , int *b)
{
    return *a + *b; 
}

*/

// Function to approximate ln(x) using a Taylor series expansion
// 
// Why do I need this function?
// ----------------------------------
// When dealing with exponentiation `base^exp` where `exp` is a floating-point number, 
// I cannot simply multiply `base` by itself `exp` times, as I do for integer exponents. 
// Instead, I must use the mathematical identity:
//
//      base^exp = e^(exp * ln(base))
//
// This allows me to break down exponentiation into two steps:
//   1. Compute `ln(base)`, the natural logarithm of the base.
//   2. Compute `e^(exp * ln(base))`, which I approximate using a Taylor series.
//
// Why not just use `ln(x) = x - 1`? (which is what I did previously) 
// ----------------------------------
// In an earlier approach, I used a rough approximation: `ln(x) ≈ x - 1`, 
// but this is only accurate for values close to 1. For better precision, 
// I now use a **Taylor series expansion** for `ln(x)`.
//
// This series converges quickly and provides better accuracy, 
// ensuring that floating-point exponents are computed correctly.
// ----------------------------------

double ln_approx(double x) {
    if (x <= 0) {
        printf("Error: Logarithm of a non-positive number is undefined.\n");
        exit(EXIT_FAILURE);
    }
    
    // Using the identity: ln(x) = 2 * [(x - 1) / (x + 1) + (1/3) * ((x - 1) / (x + 1))^3 + (1/5) * ((x - 1) / (x + 1))^5 + ...]
    double y = (x - 1) / (x + 1);
    double y2 = y * y; // (x - 1) / (x + 1) squared
    double result = 0.0;
    double term = y;
    
    for (int i = 1; i <= 9; i += 2) { // Take 5 terms for accuracy
        result += term / i;
        term *= y2;
    }
    
    return 2 * result;
}

// Function to approximate e^x using a Taylor series expansion
double exp_approx(double x) {
    double result = 1.0;
    double term = 1.0;

    for (int i = 1; i <= 12; i++) { // More terms for higher accuracy
        term *= x / i;
        result += term;
    }
    
    return result;
}

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

    // Handle fractional exponentiation
    double fractional_part = positive_exp - (int)positive_exp;
    if (fractional_part > 0) {
        double ln_base = ln_approx(base); // Use the improved logarithm function
        double frac_result = exp_approx(fractional_part * ln_base); // Compute e^(fractional_part * ln(base))
        result *= frac_result;
    }

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

    printf("the result of %.2f %c %.2f is: %.5f\n", num1, operator, num2, result);  

}
