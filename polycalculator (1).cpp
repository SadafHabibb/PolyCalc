//============================================================================
// Name         : Polynomial Calculator 
// Author       : Sadaf Habib
// Version      : 1.0
// Date Created : 5-10-2023
// Date Modified: 
// Description  : Polynomial Calculator in C++ using Singly Linked-List
//============================================================================


#include "polycalculator.h"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

// Function to take input for two polynomial expressions and store them in list1 and list2
void PolyCalculator::input() {
    // Clear the existing data in list1 and list2 before taking new input
    list1.removeAll();
    list2.removeAll();
    
    bool valid1 = false;  // track the validity of the first input
    bool valid2 = false;  // track the validity of the second input

    // Input and validation for the first polynomial expression
    while (!valid1) {
        cout << "Enter first Polynomial expression: ";
        string expression1;
        getline(cin, expression1); // Read the entire line as input
        valid1 = parse(expression1, list1);
        if (!valid1) 
            cout << "Invalid input. Please enter a valid polynomial expression." << endl;
    }

    // Input and validation for the second polynomial expression
    while (!valid2) {
        cout << "Enter second Polynomial expression: ";
        string expression2;
        getline(cin, expression2); // Read the entire line as input
        valid2 = parse(expression2, list2);
        if (!valid2) 
            cout << "Invalid input. Please enter a valid polynomial expression." << endl;
    }
}

// Function to display the polynomial expressions stored in list1 and list2
void PolyCalculator::display(ostream &os) {
    cout << "Exp 1: ";
    list1.print(os);
    cout << "Exp 2: ";
    list2.print(os);
}
void PolyCalculator::add() {
    // Clear the existing data in list3 before performing the addition
    list3.removeAll();

    Node* current1 = list1.head;
    Node* current2 = list2.head;

    while (current1 && current2) {
        if (current1->expo == current2->expo) {
            // Add terms with the same exponent
            int coefSum = current1->coef + current2->coef;
            list3.insert(coefSum, current1->expo);
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->expo > current2->expo) {
            // Add the term from list1
            list3.insert(current1->coef, current1->expo);
            current1 = current1->next;
        } else {
            // Add the term from list2
            list3.insert(current2->coef, current2->expo);
            current2 = current2->next;
        }
    }

    // Handle any remaining terms in list1 and list2
    while (current1) {
        list3.insert(current1->coef, current1->expo);
        current1 = current1->next;
    }

    while (current2) {
        list3.insert(current2->coef, current2->expo);
        current2 = current2->next;
    }

    cout << "Exp 1 + Exp2: ";
    list3.print(cout);
}






void PolyCalculator::sub() {
    // Clear the existing data in list3 before performing the subtraction
    list3.removeAll();

    Node* current1 = list1.head;
    Node* current2 = list2.head;

    while (current1 && current2) {
        if (current1->expo == current2->expo) {
            // Subtract terms with the same exponent
            int coefDiff = current1->coef - current2->coef;
            list3.insert(coefDiff, current1->expo);
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->expo > current2->expo) {
            // Add the term from list1
            list3.insert(current1->coef, current1->expo);
            current1 = current1->next;
        } else {
            // Subtract the term from list2
            list3.insert(-current2->coef, current2->expo); // Negate the coefficient
            current2 = current2->next;
        }
    }

    // Handle any remaining terms in list1 and list2
    while (current1) {
        list3.insert(current1->coef, current1->expo);
        current1 = current1->next;
    }

    while (current2) {
        list3.insert(-current2->coef, current2->expo); // Negate the coefficient
        current2 = current2->next;
    }

    cout << "Exp 1 - Exp2: ";
    list3.print(cout);
}


void PolyCalculator::mul() {
    // Clear the existing data in list3 before performing the multiplication
    list3.removeAll();

    // Start iterating through the terms in list1
    Node* current1 = list1.head;

    while (current1) {
        // For each term in list1, start iterating through the terms in list2
        Node* current2 = list2.head;

        while (current2) {
            // Calculate the product of coefficients and the sum of exponents for the current term pair
            int coefProduct = current1->coef * current2->coef;
            int expoSum = current1->expo + current2->expo;

            // Start iterating through the terms in list3 to find terms with the same exponent
            Node* current3 = list3.head;
            bool termAdded = false;

            while (current3) {
                // If a term with the same exponent is found in list3, add the coefficients
                if (current3->expo == expoSum) {
                    current3->coef += coefProduct;
                    termAdded = true;
                    break;
                }
                current3 = current3->next;
            }

            // If the term was not added to list3, insert it
            if (!termAdded) {
                list3.insert(coefProduct, expoSum);
            }

            // Move to the next term in list2
            current2 = current2->next;
        }

        // Move to the next term in list1
        current1 = current1->next;
    }

    // Display the result of the multiplication
    cout << "Exp 1 * Exp2: ";
    list3.print(cout);
}

void PolyCalculator::readData(string path) {
    // Clear the existing data in list1 and list2 before loading new data
    list1.removeAll();
    list2.removeAll();

    // Attempt to open the specified file for reading
    ifstream inputFile(path);

    // Check if the file was successfully opened
    if (!inputFile.is_open()) {
        cout << "Failed to open the file: " << path << endl;
        return; // If the file couldn't be opened, print an error message and return
    }

    string line;
    bool isFirstExpression = true;

    while (getline(inputFile, line)) {
        // Check if this line contains a polynomial expression
        if (line.empty()) {
            // Skip empty lines
            continue;
        }

        // Display the expression
        if (isFirstExpression) {
            cout << "Exp 1: ";
            isFirstExpression = false;
        } else {
            cout << "Exp 2: ";
        }

        // Parse the expression and insert it into list1 or list2
        if (parse(line, (isFirstExpression) ? list1 : list2)) {
            // Successfully parsed and inserted into list1 or list2
            cout << line << endl; // Display the valid expression
        } else {
            cout << "Invalid expression: " << line << endl; // Display invalid expressions
        }
    }

    // Close the input file when done
    inputFile.close();
}





#include <fstream>

//Function to write data in a file
void PolyCalculator::writeData(string path) {
    ofstream outputFile(path);

    if (!outputFile.is_open()) {
        cout << "Failed to open the file: " << path << endl;
        return;
    }

    // Write the first polynomial expression to the file
    outputFile << "Polynomial Expression 1:" << endl;
    list1.print(outputFile);

    // Write the second polynomial expression to the file
    outputFile << "Polynomial Expression 2:" << endl;
    list2.print(outputFile);

    // Write the result of addition to the file
    outputFile << "Addition Result:" << endl;
    list3.print(outputFile);

    // Write the result of subtraction to the file
    outputFile << "Subtraction Result:" << endl;
    // Call the sub() method to ensure list3 contains the subtraction result
    sub();
    list3.print(outputFile);

    // Write the result of multiplication to the file
    outputFile << "Multiplication Result:" << endl;
    // Call the mul() method to ensure list3 contains the multiplication result
    mul();
    list3.print(outputFile);

    outputFile.close();
}


// Function to parse a polynomial expression and insert its terms into a linked list
bool PolyCalculator::parse(string expr, LinkedList& list) {
    stringstream ss(expr); // Create a stringstream to process the input expression
    int coef = 0, exp = 0;  // Initialize variables to store coefficient and exponent
    bool valid = true;     // Initialize a flag to track the validity of the expression

    // Iterate through the input expression
    while (!ss.eof() && valid) {
        coef = 1; // Default coefficient is 1
        exp = 0;  // Default exponent is 0

        // Parse the coefficient, accounting for positive and negative signs
        if (ss.peek() == '+' || ss.peek() == '-') {
            char sign = ss.get();
            if (sign == '-') {
                coef = -1; // Set coefficient to -1 for negative terms
            }
        }

        // Parse the coefficient part of the term
        if (isdigit(ss.peek())) {
            ss >> coef;
        }
        else if (ss.peek() != 'x') {
            valid = false; // Invalid character found, set validity to false
        }

        // Parse the variable part 'x'
        if (ss.peek() == 'x') {
            ss.ignore(); // Ignore 'x'

            // Parse the exponent part, if it exists
            if (ss.peek() == '^') {
                ss.ignore(); // Ignore '^'
                if (isdigit(ss.peek())) {
                    ss >> exp; // Parse the exponent
                }
                else {
                    valid = false; // Invalid exponent, set validity to false
                }
            }
            else {
                exp = 1; // Default exponent is 1 if '^' is missing
            }
        }

        // Check for invalid characters
        if (!ss.eof() && ss.peek() != '+' && ss.peek() != '-') {
            valid = false; // Invalid character found, set validity to false
        }

        // Insert the term into the linked list if it's valid
        if (valid) {
            list.insert(coef, exp);
        }
    }

    // If the expression is invalid, remove all terms from the list
    if (!valid) {
        list.removeAll();
    }

    return valid; // Return true if the expression is valid, false otherwise
}






