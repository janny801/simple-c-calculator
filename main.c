#include <stdio.h>  // Standard input/output library
#include <stdlib.h> //for exit()


/*
int add(int *a , int *b)
{
    return *a + *b; 
}

*/

double operate(double *a, double *b, char *op)
{
    //function to calculate vals 
    switch (*op)
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
            printf("you used %c which is not supported\n", *op); 
            exit(EXIT_FAILURE); 
            return 0.0; 
            
    }
}





int main()
{
    double num1, num2; //declare variables for input
    char operator; 


    /* 
    
    printf("enter the first number: "); 
    scanf("%lf", &num1); //store input in num1 
    printf("enter the second number: "); 
    scanf("%lf", &num2); 
    */

    printf("enter the expression: "); 
    scanf("%lf %c %lf", &num1, &operator, &num2);



   double result = operate(&num1, &num2, &operator); 

   printf("the result of %.2f %c %.2f is: %.2f\n", num1, operator, num2, result);  







    




}
