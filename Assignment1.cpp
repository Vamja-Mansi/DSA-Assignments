#include <iostream>
using namespace std;

/* DEFINING A STRUCTURE NAME STUDENT WHICH CONSISTS OF ROLL NUMBER, NAME, SGPA OF FIVE STUDENTS */

struct student
{
    string name;
    int rollno;
    float sgpa;
};

// 1. BUBBLE SORT
void bubbleSort(student s[])
{
    for (int i = 0; i < 5 - 1; i++)
    {
        for (int j = 0; j < 5 - 1 - i; j++)
        {
            if (s[j].rollno > s[j + 1].rollno)
            {
                int a = s[j].rollno;
                s[j].rollno = s[j + 1].rollno;
                s[j + 1].rollno = a;
            }
        }
    }
    cout << "Sorted Roll Numbers: " << endl << "[";
    for (int j = 0; j < 5; j++)
    {
        cout << s[j].rollno << " ";
    }
    cout << "]" << endl;
}

// 2. INSERTION SORT
void insertionSort(student s[])
{
    for (int i = 0; i < 5 - 1; ++i)
    {
        for (int j = 0; j < 5 - i - 1; ++j)
        {
            if (s[j].name > s[j + 1].name)
            {
                student temp;
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    cout << "Alphabetically arranged: " << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << "Name: " << s[j].name << " , Roll Number: " << s[j].rollno << " , SGPA: " << s[j].sgpa << endl;
    }
    cout << endl;
}

// 3. QUICK SORT
int partition(student s[], int low, int high)
{
    float pivot = s[high].sgpa; // Choosing the last element as pivot
    int i = low - 1; // Index of the smaller element
    for (int j = low; j < high; j++)
    {
        if (s[j].sgpa > pivot) // Sorting in descending order
        {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return (i + 1);
}

void quickSort(student s[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

// 4. LINEAR SEARCH
void searchBySgpa(student s[], int size, float searchsgpa)
{
    bool found = false;
    cout << "STUDENTS WITH SGPA " << searchsgpa << endl;
    for (int i = 0; i < size; ++i)
    {
        if (s[i].sgpa == searchsgpa)
        {
            cout << "NAME: " << s[i].name << " , ROLL NUMBER: " << s[i].rollno << " , SGPA: " << s[i].sgpa << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "NO STUDENTS FOUND WITH SGPA " << searchsgpa << endl;
    }
}

// 5. BINARY SEARCH
void binarySearch(student s[], int low, int high, string searchName)
{
    bool found = false;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (s[mid].name == searchName)
        {
            cout << "NAME: " << s[mid].name << " , ROLL NO: " << s[mid].rollno << " , SGPA: " << s[mid].sgpa << endl;
            found = true;
            break; // Exit loop if found
        }
        else if (s[mid].name > searchName)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (!found)
    {
        cout << "No student found with the name: " << searchName << endl;
    }
}

int main()
{
    student s[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "ENTER ROLL NUMBER, NAME, SGPA OF STUDENT " << i + 1 << ":" << endl;

        cout << "ENTER YOUR NAME: " << endl;
        cin >> s[i].name;
        cout << "ENTER YOUR ROLL NUMBER: " << endl;
        cin >> s[i].rollno;
        cout << "ENTER YOUR SGPA: " << endl;
        cin >> s[i].sgpa;
        cout << endl;
    }
    
    for (int i = 0; i < 5; i++)
    {
        cout << "ROLL NUMBER, NAME, SGPA OF STUDENT " << i + 1 << " IS:" << endl;
        cout << "NAME: " << s[i].name << endl;
        cout << "ROLL NUMBER: " << s[i].rollno << endl;
        cout << "SGPA: " << s[i].sgpa << endl;
        cout << endl;
    }
    
    cout << "ENTER 1 TO PERFORM BUBBLE SORT" << endl;
    cout << "ENTER 2 TO PERFORM INSERTION SORT" << endl;
    cout << "ENTER 3 TO PERFORM QUICK SORT" << endl;
    cout << "ENTER 4 TO PERFORM LINEAR SEARCH" << endl;
    cout << "ENTER 5 TO PERFORM BINARY SEARCH" << endl;
    cout << endl;

    int func = 1;
    while (func == 1)
    {
        int choice;
        cout << "ENTER YOUR CHOICE: " << endl;
        cin >> choice;
        
        if (choice == 1)
        {
            cout << "***** PERFORMING BUBBLE SORT *****" << endl;
            bubbleSort(s);
            cout << endl;
            cout << "Press 1 to continue and 0 to exit: " << endl;
            cin >> func;
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << "***** PERFORMING INSERTION SORT *****" << endl;
            insertionSort(s);
            cout << "Press 1 to continue and 0 to exit: " << endl;
            cin >> func;
            cout << endl;
        }
        else if (choice == 3)
        {
            cout << "***** PERFORMING QUICK SORT *****" << endl;
            quickSort(s, 0, 5 - 1);
            cout << "Top 3 Toppers:" << endl;
            cout << endl;
            for (int i = 0; i < 3 && i < 5; ++i)
            {
                cout << "Name: " << s[i].name << " , Roll No: " << s[i].rollno << " , SGPA: " << s[i].sgpa << endl;
            }
            cout << "Press 1 to continue and 0 to exit: " << endl;
            cin >> func;
            cout << endl;
        }
        else if (choice == 4)
        {
            float searchsgpa;
            cout << "ENTER SGPA TO SEARCH: " << endl;
            cin >> searchsgpa;
            searchBySgpa(s, 5, searchsgpa);
            cout << "Press 1 to continue and 0 to exit: " << endl;
            cin >> func;
            cout << endl;
        }
        else if (choice == 5)
        {
            cout << "***** PERFORMING BINARY SEARCH *****" << endl;
            string searchName;
            cout << "Enter the name of the student to search: ";
            cin >> searchName;
            cout << endl;
            binarySearch(s, 0, 5 - 1, searchName);
            cout << endl;
            cout << "Press 1 to continue and 0 to exit: " << endl;
            cin >> func;
            cout << endl;
        }
        else
        {
            cout << "INVALID" << endl;
            cout << "Press 1 to continue and 0 to exit: " << endl;
            cin >> func;
            cout << endl;
        }
    }

    return 0;
}

