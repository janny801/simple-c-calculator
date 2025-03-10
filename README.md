# Simple Calculator in C

This is a simple command-line calculator written in C. It takes two numbers (integers and/or floating-point) as input and performs the corresponding arithmetic operation. The program outputs floating-point values.


## Features

- Supports addition (`+`), subtraction (`-`), multiplication (`*` or `x`), and division (`/`).
- Handles division by zero with an error message.
- Uses pointers for passing values to functions.
- Ignores extra whitespaces in the input, ensuring only the required values (operator and operands) are processed correctly.
- Supports both integer and floating-point inputs.


## Requirements

- A C compiler (`gcc` recommended)
- A terminal or command-line interface
- Works on Linux, macOS, and Windows (via WSL or MinGW)



## Compilation and Execution

1. **Compile the Program**  
   Run the following command in your terminal:  

   ```bash
   gcc -o calculator main.c
   ```

   This will generate an executable named `calculator`.

   This command uses the GNU Compiler Collection (gcc) to compile main.c into an executable named calculator. The -o calculator option specifies the output filename.
   
   - **Why is this step necessary?**  
  C and C++ programs are written in human-readable source code, but computers cannot execute this code directly. The compiler translates it into machine code (binary) that the operating system can run.



2. **Run the Program**  

   ```bash
   ./calculator
   ```

## Usage

When prompted, enter an expression in the format:  
enter the expression: <num1> <operator> <num2>  

For example:  
enter the expression: 10 + 5  

Output:  
the result of 10 + 5 is: 15.00000  

Another example:  
enter the expression: 7 * 2.5  

Output:  
the result of 7 * 2.5 is: 17.50000  

Exponentiation example:  
enter the expression: 2.1 ^ 2.1  

Output:  
the result of 2.10 ^ 2.10 is: 4.74964  


## Error Handling

- If division by zero is attempted, the program prints an error message and exits.
- If an unsupported operator is entered, the program prints an error message and exits.


## Example Inputs and Outputs

| Input    | Output                                       |
| -------- | -------------------------------------------- |
| 10 + 5   | the result of 10 + 5 is: 15.00000           |
| 20 - 4   | the result of 20 - 4 is: 16.00000           |
| 6 * 3    | the result of 6 * 3 is: 18.00000           |
| 7 * 2.5  | the result of 7 * 2.5 is: 17.50000          |
| 10 / 2   | the result of 10 / 2 is: 5.00000            |
| 5 / 0    | error: division by 0                        |
| 2 ^ 3    | the result of 2 ^ 3 is: 8.00000             |
| 2.1 ^ 2.1 | the result of 2.10 ^ 2.10 is: 4.74964      |



## Future Improvements

- Allow input from a file instead of only manual input.
- Add support for parentheses to control the order of operations.
- Include additional operations such as modulus (`%`) and bitwise operators.
- Implement support for square root (`√`), logarithm (`log` and `ln`), and trigonometric functions (`sin`, `cos`, `tan`).
- Enable support for scientific notation and complex numbers.
- Improve error handling for invalid inputs and undefined operations.
