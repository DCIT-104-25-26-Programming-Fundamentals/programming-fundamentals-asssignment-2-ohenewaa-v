// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
#include <iomanip>

void printSingleTable(int num) {
    cout << "\nMultiplication Table for " << num << ":" << endl;
    cout << "-------------------------" << endl;
    
    for (int i = 1; i <= 12; i++) {
        cout << setw(3) << num << "  x  " << setw(2) << i << "  =  " << setw(3) << (num * i) << endl;
    }
}

void printMultipleTables(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }
    
    for (int num = 1; num <= n; num++) {
        printSingleTable(num);
        
        if (num < n) {
            cout << "\n---------------------------" << endl;
            cout << "---------------------------\n" << endl;
        }
    }
}

int showMenu() {
    int choice;
    cout << "\n=== MULTIPLICATION TABLE MENU ===" << endl;
    cout << "1. Print table for a single number (1-12)" << endl;
    cout << "2. Print tables from 1 to N" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    return choice;
}

int main() {
    int choice;
    
    do {
        choice = showMenu();
        
        switch (choice) {
            case 1: {  
                int num;
                cout << "\nEnter a number: ";
                cin >> num;
                
                if (num < 1 || num > 12) {
                    cout << "Error: Please enter a number between 1 and 12." << endl;
                } else {
                    printSingleTable(num);
                }
                break;
            }
            
            case 2: {  
                int n;
                cout << "\nEnter N (positive integer): ";
                cin >> n;
                printMultipleTables(n);
                break;
            }
            
            case 3: {  
                cout << "Goodbye!" << endl;
                break;
            }
            
            default: {
                cout << "Invalid choice! Please enter 1-3." << endl;
            }
        }
        
    } while (choice != 3);
    
    return 0;
}
