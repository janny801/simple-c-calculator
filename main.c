#include <stdio.h>  // Standard input/output library
#include <stdlib.h> //for exit()
#include <ctype.h>  // For isspace() and isdigit()




// Global pointer for parsing input
char *input_ptr;


// Function prototypes for the parser functions
double parseExpression(void);
double parseTerm(void);
double parseFactor(void);
double parsePrimary(void);


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

/* 
   Function to compute the modulus operation without using the math.h library.
   This function supports both integer and floating-point modulus calculations.
*/
double modulus(double a, double b) {
    // Check if the divisor (b) is zero.
    // The modulus operation is undefined when dividing by zero, 
    // so we print an error message and terminate the program.
    if (b == 0) {
        printf("error: modulus by 0 is undefined\n");
        exit(EXIT_FAILURE);
    }
    
    // If both numbers are integers, perform the modulus operation 
    // using the standard integer modulus operator `%`.
    if ((int)a == a && (int)b == b) {
        return (int)a % (int)b;
    }

    // For floating-point numbers, we approximate the modulus using iterative subtraction.
    // This simulates the behavior of the modulus operation for real numbers.

    // Store the initial value of 'a' in 'result'
    double result = a;

    // Subtract 'b' from 'result' repeatedly until it falls within the correct range.
    // This ensures that the remainder is within [0, b) for positive numbers.
    while (result >= b) {
        result -= b;
    }

    // If 'result' is negative, adjust it by adding 'b' to bring it into the correct range.
    // This is necessary to correctly handle negative values.
    while (result < 0) {
        result += b;
    }
    
    // Return the computed remainder
    return result;
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
        case '%': // Modulus case
            return modulus(*a, *b);
        default: 
            printf("you used %c which is not supported\n", op); // Removed * since op is now a value
            exit(EXIT_FAILURE); 
            return 0.0; 
            
    }
}

// parseExpression handles + and -
double parseExpression(void) {
    double value = parseTerm();
    while (1) {
        // Skip any spaces so we can see if there's a '+' or '-'
        while (isspace(*input_ptr)) {
            input_ptr++;
        }
        if (*input_ptr == '+' || *input_ptr == '-') {
            char op = *input_ptr++;
            double term = parseTerm();
            if (op == '+') {
                value += term;
            } else {
                value -= term;
            }
        } else {
            break; // No more + or -
        }
    }
    return value;
}

// parseTerm handles *, /, %
double parseTerm(void) {
    double value = parseFactor();
    while (1) {
        // Skip spaces before checking for * / %
        while (isspace(*input_ptr)) {
            input_ptr++;
        }
        if (*input_ptr == '*' || *input_ptr == '/' || *input_ptr == '%') {
            char op = *input_ptr++;
            double factor = parseFactor();
            if (op == '*') {
                value *= factor;
            } else if (op == '/') {
                value /= factor;
            } else { // '%'
                // Very simplistic integer-only mod for illustration
                value = (int)value % (int)factor;
            }
        } else {
            break; // No more * / %
        }
    }
    return value;
}

// parseFactor handles ^ (exponentiation)
double parseFactor(void) {
    double value = parsePrimary();
    while (1) {
        // Skip spaces before checking for ^
        while (isspace(*input_ptr)) {
            input_ptr++;
        }
        if (*input_ptr == '^') {
            input_ptr++; // consume '^'
            double exponent = parseFactor(); // right-associative
            value = power(value, exponent);
        } else {
            break; // No more ^
        }
    }
    return value;
}

// parsePrimary handles numbers, parentheses, unary +/- 
double parsePrimary(void) {
    // Skip spaces before we decide what we're looking at
    while (isspace(*input_ptr)) {
        input_ptr++;
    }

    double value = 0.0;
    
    // Parenthesized expression?
    if (*input_ptr == '(') {
        input_ptr++; // skip '('
        value = parseExpression();
        if (*input_ptr == ')') {
            input_ptr++; // skip ')'
        } else {
            printf("Error: missing closing parenthesis.\n");
            exit(EXIT_FAILURE);
        }
    }
    // Unary minus
    else if (*input_ptr == '-') {
        input_ptr++;
        value = -parsePrimary();
    }
    // Unary plus (rarely used, but let's handle it)
    else if (*input_ptr == '+') {
        input_ptr++;
        value = parsePrimary();
    }
    // Otherwise, parse a number
    else {
        if (sscanf(input_ptr, "%lf", &value) != 1) {
            printf("Error: invalid number.\n");
            exit(EXIT_FAILURE);
        }
        // Advance input_ptr past the digits, decimal, or exponent
        while (*input_ptr && (isdigit(*input_ptr) || *input_ptr == '.' ||
               *input_ptr == 'e' || *input_ptr == 'E'))
        {
            input_ptr++;
        }
    }
    return value;
}



int main() {
    char input[256];
    
    printf("Enter the expression: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }
    
    input_ptr = input;
    double result = parseExpression();
    printf("Result: %.5f\n", result);
    return 0;
}
