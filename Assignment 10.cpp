#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    string division;
    string address;
};

// Function to add student record
void addStudent(const string& filename) {
    ofstream outFile(filename, ios::app); // Open file in append mode
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNo;
    cin.ignore(); // To ignore the newline character left by cin >> student.rollNo
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    // Write to file
    outFile << student.rollNo << endl;
    outFile << student.name << endl;
    outFile << student.division << endl;
    outFile << student.address << endl;

    outFile.close();
    cout << "Student record added successfully!" << endl;
}

// Function to delete student record
void deleteStudent(const string& filename) {
    int rollNoToDelete;
    cout << "Enter Roll Number to delete: ";
    cin >> rollNoToDelete;

    ifstream inFile(filename);
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    bool found = false;
    Student student;

    while (inFile >> student.rollNo) {
        inFile.ignore(); // To ignore the newline character
        getline(inFile, student.name);
        getline(inFile, student.division);
        getline(inFile, student.address);

        if (student.rollNo != rollNoToDelete) {
            tempFile << student.rollNo << endl;
            tempFile << student.name << endl;
            tempFile << student.division << endl;
            tempFile << student.address << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    // If the record was found, replace the original file with the temp file
    if (found) {
        remove(filename.c_str()); // Delete the original file
        rename("temp.txt", filename.c_str()); // Rename temp.txt to the original file name
        cout << "Student record deleted successfully!" << endl;
    } else {
        cout << "Student record not found!" << endl;
    }
}

// Function to display student record
void displayStudent(const string& filename) {
    int rollNoToFind;
    cout << "Enter Roll Number to display: ";
    cin >> rollNoToFind;

    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    bool found = false;

    while (inFile >> student.rollNo) {
        inFile.ignore(); // To ignore the newline character
        getline(inFile, student.name);
        getline(inFile, student.division);
        getline(inFile, student.address);

        if (student.rollNo == rollNoToFind) {
            cout << "Student Found!" << endl;
            cout << "Roll Number: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found) {
        cout << "Student record not found!" << endl;
    }
}

// Main menu for the user to select actions
void displayMenu() {
    cout << "\nStudent Database Management System" << endl;
    cout << "1. Add Student Record" << endl;
    cout << "2. Delete Student Record" << endl;
    cout << "3. Display Student Record" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    const string filename = "students.txt"; // The file where student data will be stored

    while (true) {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                deleteStudent(filename);
                break;
            case 3:
                displayStudent(filename);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

