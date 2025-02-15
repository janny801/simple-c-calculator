# Simple Calculator in C

This is a simple command-line calculator written in C. It takes two integers and an operator as input and performs the corresponding arithmetic operation.


## Features

- Supports addition (+), subtraction (-), multiplication (* or x), and division (/).
- Handles division by zero with an error message.
- Uses pointers for passing values to functions.



## Compilation and Execution

1. **Compile the Program**  
   Run the following command in your terminal:  
   gcc -o calculator main.c  

   This will generate an executable named `calculator`.

2. **Run the Program**  
   ./calculator  

## Usage

When prompted, enter an expression in the format:  
enter the expression: <num1> <operator> <num2>  

For example:  
enter the expression: 10 + 5  

Output:  
the result of 10 + 5 is: 15.00  

## Error Handling

- If division by zero is attempted, the program prints an error message and exits.
- If an unsupported operator is entered, the program prints an error message and exits.


## Example Inputs and Outputs

| Input  | Output                            |
| ------ | --------------------------------- |
| 10 + 5 | the result of 10 + 5 is: 15.00    |
| 20 - 4 | the result of 20 - 4 is: 16.00    |
| 6 * 3  | the result of 6 * 3 is: 18.00     |
| 10 / 2 | the result of 10 / 2 is: 5.00     |
| 5 / 0  | error: division by 0              |



