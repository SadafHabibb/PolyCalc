# PolyCalc


```markdown
# Polynomial Calculator

## Overview
The Polynomial Calculator is a C++ program that performs arithmetic operations on polynomial expressions. It uses a singly linked list to represent each polynomial, enabling efficient insertion, deletion, and manipulation of terms.

### Features
- **Addition** of two polynomials
- **Subtraction** of one polynomial from another
- **Multiplication** of two polynomials
- **Input and output** support for reading from the console or files
- **File operations** for reading polynomial data from a file and writing the results to a file

## Getting Started

### Prerequisites
- A C++ compiler (e.g., GCC)
- Basic understanding of polynomial arithmetic

### Project Structure
- `polycalculator.cpp`: Main implementation of the Polynomial Calculator.
- `polycalculator.h`: Header file for the Polynomial Calculator class.
- `LinkedList.h`: Header file for the Linked List data structure used to represent polynomials.
- `Node.h`: Header file for the Node structure used in the linked list.
- `main.cpp`: Entry point of the program with a simple menu to demonstrate functionality.

### Compilation
To compile the project, use the following command:

```bash
g++ -o polycalc main.cpp polycalculator.cpp LinkedList.cpp
```

### Running the Program
After compilation, run the program:

```bash
./polycalc
```

Follow the on-screen instructions to enter polynomial expressions and perform operations.

## Usage

### Input Format
- Polynomial expressions should be entered in standard mathematical notation (e.g., `3x^2 + 2x - 5`).
- Terms can include:
  - Positive or negative coefficients
  - Variables (`x`)
  - Optional exponents (e.g., `x^2`)
  - Constants without variables (e.g., `+3`)

### Menu Options
The program supports the following operations:
1. **Addition**: Adds two polynomial expressions.
2. **Subtraction**: Subtracts the second polynomial from the first.
3. **Multiplication**: Multiplies two polynomial expressions.
4. **Display**: Displays the current polynomials.
5. **Read from File**: Reads polynomial expressions from a specified file.
6. **Write to File**: Writes the current polynomial expressions and results to a specified file.

### File Operations
- **Reading from a File**: The program can read polynomial expressions from a text file, where each line contains one polynomial expression.
- **Writing to a File**: The program writes the input polynomials and the results of addition, subtraction, and multiplication to a specified output file.

## Code Structure

### `PolyCalculator` Class
This class provides methods to perform arithmetic operations on polynomials using linked lists.

- **`input()`**: Takes input for two polynomials and stores them in the linked lists.
- **`display()`**: Prints the polynomials to the console.
- **`add()`**: Adds two polynomials.
- **`sub()`**: Subtracts the second polynomial from the first.
- **`mul()`**: Multiplies two polynomials.
- **`readData(string path)`**: Reads polynomial data from a file.
- **`writeData(string path)`**: Writes polynomial data and results to a file.
- **`parse(string expr, LinkedList &list)`**: Parses a polynomial expression and inserts the terms into a linked list.

### `LinkedList` and `Node` Structures
- **`LinkedList`**: A singly linked list used to store polynomial terms (coefficient and exponent).
- **`Node`**: Represents a term in the polynomial, with a coefficient and an exponent.

## Example
Sample input and output interaction:

```plaintext
Enter first Polynomial expression: 3x^2 + 2x - 5
Enter second Polynomial expression: 4x^3 + x - 2

Exp 1: 3x^2 + 2x - 5
Exp 2: 4x^3 + x - 2

Exp 1 + Exp 2: 4x^3 + 3x^2 + 3x - 7
Exp 1 - Exp 2: -4x^3 + 3x^2 + x - 3
Exp 1 * Exp 2: 12x^5 + 8x^4 - 20x^3 + 11x^2 - 12x + 10
```

## Error Handling
- The program validates polynomial input and provides feedback if the input format is incorrect.
- It checks file operations for successful opening and reports errors if a file cannot be accessed.

## Future Enhancements
- Support for division of polynomials.
- Improved input parsing for more flexible polynomial formats.
- Graphical user interface (GUI) for easier user interaction.

## Author
- **Sadaf Habib**

## Version
- **1.0** (Created: 5-10-2023)

## License
This project is licensed under the MIT License.

