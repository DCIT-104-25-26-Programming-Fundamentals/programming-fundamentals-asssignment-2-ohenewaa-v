// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <limits>

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void showMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

double calculateAverage(const Student& student) {
    if (student.scores.empty()) {
        return 0.0;
    }
    
    double sum = 0.0;
    for (double score : student.scores) {
        sum += score;
    }
    return sum / student.scores.size();
}

void addStudent(vector<Student>& students) {
    Student newStudent;
    
    cout << "Student name: ";
    cin.ignore();  
    getline(cin, newStudent.name);
    
    if (newStudent.name.empty()) {
        cout << "Error: Student name cannot be empty." << endl;
        return;
    }
    
    cout << "Student ID: ";
    cin >> newStudent.id;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid ID. Please enter a number." << endl;
        return;
    }
    
    for (const Student& s : students) {
        if (s.id == newStudent.id) {
            cout << "Error: Student ID " << newStudent.id << " already exists." << endl;
            return;
        }
    }
    
    int numScores;
    cout << "How many scores? ";
    cin >> numScores;
    
    if (cin.fail() || numScores < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid number of scores." << endl;
        return;
    }
    
    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        
        if (cin.fail() || score < 0 || score > 100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid score. Score must be between 0 and 100." << endl;
            return;
        }
        
        newStudent.scores.push_back(score);
    }
    
    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }
    
    cout << "\n" << string(80, '=') << endl;
    cout << setw(5) << "No." << setw(25) << "Name" << setw(12) << "ID" 
         << setw(20) << "Scores" << setw(15) << "Average" << endl;
    cout << string(80, '-') << endl;
    
    for (size_t i = 0; i < students.size(); i++) {
        const Student& s = students[i];
        
        cout << setw(5) << i + 1 
             << setw(25) << s.name 
             << setw(12) << s.id;
        
        cout << " [";
        for (size_t j = 0; j < s.scores.size(); j++) {
            cout << s.scores[j];
            if (j < s.scores.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        
        double avg = calculateAverage(s);
        cout << setw(15) << fixed << setprecision(2) << avg << endl;
    }
    cout << string(80, '=') << endl;
}

int findStudentById(const vector<Student>& students, int id) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            return i;  
        }
    }
    return -1;  
}

void calculateStudentAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "Error: No students have been added yet." << endl;
        return;
    }
    
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid ID. Please enter a number." << endl;
        return;
    }
    
    int index = findStudentById(students, id);
    
    if (index == -1) {
        cout << "Error: Student with ID " << id << " not found." << endl;
        return;
    }
    
    const Student& student = students[index];
    double avg = calculateAverage(student);
    
    cout << student.name << "'s average score: " 
         << fixed << setprecision(2) << avg << endl;
}

int main() {
    vector<Student> students;  
    int choice;
    
    cout << "Welcome to the Student Record Management System!" << endl;
    cout << "=================================================" << endl;
    
    do {
        showMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter a number between 1 and 4." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                addStudent(students);
                break;
                
            case 2:
                displayAllStudents(students);
                break;
                
            case 3:
                calculateStudentAverage(students);
                break;
                
            case 4:
                cout << "\nGoodbye! Have a great day!" << endl;
                break;
                
            default:
                cout << "Error: Invalid choice. Please enter a number between 1 and 4." << endl;
        }
        
    } while (choice != 4);
    
    return 0;
}

