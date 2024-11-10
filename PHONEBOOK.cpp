#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Struct to represent a contact
struct Contact {
    string name;
    string phoneNumber;
};

// Global unordered map to store Contact
unordered_map<string , Contact> contacts;

// Function to Add contacts
void addContacts(const string& name , const string& phoneNumber) {
    Contact contact = {name , phoneNumber};
    contacts[name] = contact;
    cout << "Contact added: " << name << " " << phoneNumber << endl;
}

// Function to Delete contact
void deleteContacts(const string& name) {
    if(contacts.erase(name)) {
        cout << "Contact deleted: " << name << endl;
    }
    else {
        cout << "Contact not found: " << name << endl;
    }
}

// Function to Search a contact by name
void searchByName(const string& name) {
    auto x = contacts.find(name);
    if(x != contacts.end()) {
        cout << "Contact found: " << x->second.name << " - " << x->second.phoneNumber << endl;
    }
    else {
        cout << "Contact not found: " << name << endl;
    }
}

// Function to Search a contact by number
void searchByPhoneNumber(const string& phoneNumber) {
    for (const auto& contact : contacts) {
        if (contact.second.phoneNumber == phoneNumber) {
            cout << "Contact found: " << contact.second.name << " - " << contact.second.phoneNumber << endl;
            return;
        }
    }
    cout << "Contact not found with number: " << phoneNumber << endl;
}

// Function to Update a contact
void updateContact(const string& name, const string& newNumber) {
    auto it = contacts.find(name);
    if (it != contacts.end()) {
        it->second.phoneNumber = newNumber;
        cout << "Contact updated: " << name << " - " << newNumber << endl;
    } else {
        cout << "Contact not found: " << name << endl;
    }
}

// Function to check whether a contact exists or not
bool contactExists(const string& name) {
    return contacts.find(name) != contacts.end();
}

// Function to count the contacts
int countContacts() {
    return contacts.size();
}

// Function to clear all contacts
void clearContacts() {
    contacts.clear();
    cout << "All contacts cleared." << endl;
}

// Function to display all contacts
void displayContacts() {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
        return;
    }
    for (const auto& contact : contacts) {
        cout << "Name: " << contact.second.name << ", Phone: " << contact.second.phoneNumber << endl;
    }
}

int main()
{
    int choice;
    string name, phoneNumber;

    do {
        cout << "********* Phone Book Menu *********" << endl;
        cout << "1. Add Contacts " << endl;
        cout << "2. Delete Contacts " << endl;
        cout << "3. Search contacts by name" << endl;
        cout << "4. Search contacts by Phone number" << endl;
        cout << "5. Update contact" << endl;
        cout << "6. Check If contact exists" << endl;
        cout << "7. Count Total Contacts" << endl;
        cout << "8. Clear All Contacts" << endl;
        cout << "9. Display All Contacts" << endl;
        cout << "10. Exit....." << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phoneNumber;
                addContacts(name, phoneNumber);
                break;

            case 2:
                cout << "Enter name to delete: ";
                cin >> name;
                deleteContacts(name);
                break;

            case 3:
                cout << "Enter name to search: ";
                cin >> name;
                searchByName(name);
                break;

            case 4:
                cout << "Enter phone number to search: ";
                cin >> phoneNumber;
                searchByPhoneNumber(phoneNumber);
                break;

            case 5:
                cout << "Enter name to update: ";
                cin >> name;
                cout << "Enter new phone number: ";
                cin >> phoneNumber;
                updateContact(name, phoneNumber);
                break;

            case 6:
                cout << "Enter name to check if exists: ";
                cin >> name;
                if (contactExists(name)) {
                    cout << "Contact exists: " << name << endl;
                } else {
                    cout << "Contact does not exist: " << name << endl;
                }
                break;

            case 7:
                cout << "Total contacts: " << countContacts() << endl;
                break;

            case 8:
                clearContacts();
                break;

            case 9:
                displayContacts();
                break;

            case 10:
                cout << "Exiting...." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;

    } while (choice != 10);

    return 0;
}

