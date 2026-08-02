// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#include <limits>

void showMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

void getTwoNumbers(double& num1, double& num2) {
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
}

void getTwoIntegers(int& num1, int& num2) {
    cout << "Enter first integer: ";
    cin >> num1;
    cout << "Enter second integer: ";
    cin >> num2;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0;
    }
    return a / b;
}

int calculateModulus(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot perform modulus by zero." << endl;
        return 0;
    }
    return a % b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

bool isValidNumber(double& num) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid input. Please enter a number." << endl;
        return false;
    }
    return true;
}

bool isValidInteger(int& num) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid input. Please enter an integer." << endl;
        return false;
    }
    return true;
}

void displayResult(const string& operation, double num1, double num2, double result) {
    cout << fixed << setprecision(2);
    cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
}

void displayIntegerResult(const string& operation, int num1, int num2, int result) {
    cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
}

int main() {
    int choice;
    double num1, num2;
    int int1, int2;
    double result;
    int intResult;
    
    cout << "Welcome to the Simple Calculator!" << endl;
    cout << "=================================" << endl;
    
    do {
        showMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter a number between 1 and 7." << endl;
            continue;
        }
        
        switch (choice) {
            case 1: {  
                getTwoNumbers(num1, num2);
                if (!isValidNumber(num1) || !isValidNumber(num2)) break;
                result = add(num1, num2);
                displayResult("+", num1, num2, result);
                break;
            }
            
            case 2: {  
                getTwoNumbers(num1, num2);
                if (!isValidNumber(num1) || !isValidNumber(num2)) break;
                result = subtract(num1, num2);
                displayResult("-", num1, num2, result);
                break;
            }
            
            case 3: {  
                getTwoNumbers(num1, num2);
                if (!isValidNumber(num1) || !isValidNumber(num2)) break;
                result = multiply(num1, num2);
                displayResult("*", num1, num2, result);
                break;
            }
            
            case 4: {  
                getTwoNumbers(num1, num2);
                if (!isValidNumber(num1) || !isValidNumber(num2)) break;
                result = divide(num1, num2);
                if (num2 != 0) {
                    displayResult("/", num1, num2, result);
                }
                break;
            }
            
            case 5: {  
                getTwoIntegers(int1, int2);
                if (!isValidInteger(int1) || !isValidInteger(int2)) break;
                intResult = calculateModulus(int1, int2);
                if (int2 != 0) {
                    displayIntegerResult("%", int1, int2, intResult);
                }
                break;
            }
            
            case 6: {  
                getTwoNumbers(num1, num2);
                if (!isValidNumber(num1) || !isValidNumber(num2)) break;
                result = power(num1, num2);
                displayResult("^", num1, num2, result);
                break;
            }
            
            case 7: {  
                cout << "\nGoodbye! Thank you for using the calculator." << endl;
                break;
            }
            
            default: {
                cout << "Error: Invalid choice. Please select an option between 1 and 7." << endl;
            }
        }
        
    } while (choice != 7);
    
    return 0;
}
