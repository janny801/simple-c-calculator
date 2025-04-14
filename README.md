# Simple Calculator in C

This is a simple command-line calculator written in C. It accepts a complete arithmetic expression that can include multiple numbers (integers and/or floating-point), various arithmetic operators, and parentheses. The calculator supports addition, subtraction, multiplication, division, exponentiation, and modulus. It applies standard operator precedence (PEMDAS) to evaluate the expression and outputs the result as a floating-point value.


## Features

- Supports addition (`+`), subtraction (`-`), multiplication (`*` or `x`), and division (`/`).
- Supports exponentiation (`^`) for both integer and floating-point values.
- Handles division by zero with an error message.
- Uses pointers for passing values to functions.
- Ignores extra whitespaces in the input, ensuring only the required values (operator and operands) are processed correctly.
- Implements natural logarithm (`ln(x)`) and exponentiation (`e^x`) approximations using a Taylor series.
- Provides graceful error handling for invalid inputs and undefined operations.
- Ensures consistent formatted output with a fixed decimal precision.


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

   This executes the compiled program. The `./` prefix tells the system to run the `calculator` executable in the current directory.


## Usage

When prompted, enter a full arithmetic expression containing multiple numbers and operators.  
The calculator now supports expressions with proper operator precedence (PEMDAS) and parentheses.

**Examples:**

- **Simple expression:**  
  **Input:**  
  `Enter the expression: 10 + 5`  
  **Output:**  
  `Result: 15.00000`

- **Multiple operations:**  
  **Input:**  
  `Enter the expression: 7 + 2.5 * 3`  
  **Output:**  
  `Result: 14.50000`  
  *(Multiplication is performed before addition.)*

- **Using parentheses:**  
  **Input:**  
  `Enter the expression: (7 + 2.5) * 3`  
  **Output:**  
  `Result: 28.50000`

- **Exponentiation:**  
  **Input:**  
  `Enter the expression: 2.1 ^ 2.1`  
  **Output:**  
  `Result: 4.74964`

- **Modulus:**  
  **Input:**  
  `Enter the expression: 3 % 10`  
  **Output:**  
  `Result: 3.00000`

  - **Parentheses error handling:**  
  **Input:**  
  `Enter the expression: (2+3))`  
  **Output:**  
  `Error: too many closing parentheses.`




## Error Handling

- If division by zero is attempted, the program prints an error message and exits.
- If an unsupported operator is entered, the program prints an error message and exits.


## Example Inputs and Outputs

| Input         | Output                                       |
| ------------- | -------------------------------------------- |
| 10 + 5        | the result of 10 + 5 is: 15.00000             |
| 20 - 4        | the result of 20 - 4 is: 16.00000             |
| 6 * 3         | the result of 6 * 3 is: 18.00000              |
| 7 * 2.5       | the result of 7 * 2.5 is: 17.50000            |
| 10 / 2        | the result of 10 / 2 is: 5.00000              |
| 5 / 0         | error: division by 0                         |
| 2 ^ 3         | the result of 2 ^ 3 is: 8.00000               |
| 2.1 ^ 2.1     | the result of 2.10 ^ 2.10 is: 4.74964         |
| 3 % 10        | the result of 3 % 10 is: 3.00000              |
| 2 + 3 * 4     | the result of 2 + 3 * 4 is: 14.00000          |


## Future Improvements

- Allow input from a file instead of only manual input.
- Add support for parentheses to control the order of operations.
- Implement support for square root (`√`), logarithm (`log` and `ln`), and trigonometric functions (`sin`, `cos`, `tan`).
- Enable support for scientific notation and complex numbers.
- Improve error handling for invalid inputs and undefined operations.
- Add support for user-defined functions, allowing users to store and reuse expressions.
