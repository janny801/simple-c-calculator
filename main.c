#include <stdio.h>  // Standard input/output library
#include <stdlib.h> //for exit()


/*
int add(int *a , int *b)
{
    return *a + *b; 
}

*/

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

    // Debugging output to check values
    printf("Debug: num1 = %.2f, operator = '%c' (ASCII: %d), num2 = %.2f\n", num1, operator, operator, num2);

    double result = operate(&num1, &num2, operator); // Passed operator by value

    printf("the result of %.2f %c %.2f is: %.2f\n", num1, operator, num2, result);  

}
