// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int MAX_SIZE = 10;

void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    int transposed[MAX_SIZE][MAX_SIZE] = {0};
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, cols);
    
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows);
}

void addMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], 
                 int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE] = {0};
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    cout << "\nMatrix A:" << endl;
    displayMatrix(matrix1, rows, cols);
    
    cout << "\nMatrix B:" << endl;
    displayMatrix(matrix2, rows, cols);
    
    cout << "\nSum (A + B):" << endl;
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE],
                      int rowsA, int colsA, int colsB) {
    int result[MAX_SIZE][MAX_SIZE] = {0};
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    cout << "\nMatrix A:" << endl;
    displayMatrix(matrixA, rowsA, colsA);
    
    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB, colsA, colsB);
    
    cout << "\nProduct (A × B):" << endl;
    displayMatrix(result, rowsA, colsB);
}

void readMatrix(int matrix[][MAX_SIZE], int rows, int cols, string name) {
    cout << "\nEnter elements for " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

int showMenu() {
    int choice;
    cout << "\n=== MATRIX OPERATIONS MENU ===" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    return choice;
}

int main() {
    int choice;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    
    do {
        choice = showMenu();
        
        switch (choice) {
            case 1: {  
                cout << "\n--- TRANSPOSE MATRIX ---" << endl;
                cout << "Enter number of rows: ";
                cin >> rowsA;
                cout << "Enter number of columns: ";
                cin >> colsA;
                
                if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) {
                    cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << endl;
                    break;
                }
                
                readMatrix(matrixA, rowsA, colsA, "Matrix");
                transposeMatrix(matrixA, rowsA, colsA);
                break;
            }
            
            case 2: {  
                cout << "\n--- ADD TWO MATRICES ---" << endl;
                cout << "Enter number of rows: ";
                cin >> rowsA;
                cout << "Enter number of columns: ";
                cin >> colsA;
                
                if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) {
                    cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << endl;
                    break;
                }
                
                readMatrix(matrixA, rowsA, colsA, "Matrix A");
                readMatrix(matrixB, rowsA, colsA, "Matrix B");
                addMatrices(matrixA, matrixB, rowsA, colsA);
                break;
            }
            
            case 3: {  
                cout << "\n--- MULTIPLY TWO MATRICES ---" << endl;
                cout << "Enter rows for Matrix A: ";
                cin >> rowsA;
                cout << "Enter columns for Matrix A (also rows for Matrix B): ";
                cin >> colsA;
                cout << "Enter columns for Matrix B: ";
                cin >> colsB;
                
                if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE ||
                    colsB <= 0 || colsB > MAX_SIZE) {
                    cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << endl;
                    break;
                }
                
                readMatrix(matrixA, rowsA, colsA, "Matrix A");
                readMatrix(matrixB, colsA, colsB, "Matrix B");
                multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);
                break;
            }
            
            case 4: {  
                cout << "Goodbye!" << endl;
                break;
            }
            
            default: {
                cout << "Invalid choice! Please enter 1-4." << endl;
            }
        }
        
    } while (choice != 4);
    
    return 0;
}
