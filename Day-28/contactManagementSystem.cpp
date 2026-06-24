#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct contact {
    string name;
    string email;
    long long phoneNumber;
    string address;
};
// Function prototypes
void addContact(vector<contact>& contacts, const contact& newContact);
void viewContactDetails(const vector<contact>& contacts, const string& name);
void loadContactsFromFile(vector<contact>& contacts, const string& filename);
void saveContactsToFile(const vector<contact>& contacts, const string& filename);
void displayAllContacts(const vector<contact>& contacts);
void searchCOntactbyNumber(const vector<contact>& contacts, long long phoneNumber);
void sortContactsByName(vector<contact>& contacts);


int main () {
    vector<contact> contacts;
    loadContactsFromFile(contacts, "contacts.csv");
    int choice;
    do {
        cout << "Contact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contact Details" << endl;
        cout << "3. Display All Contacts" << endl;
        cout << "4. Search Contact by Phone Number" << endl;
        cout << "5. Sort Contacts by Name" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                contact newContact;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, newContact.name);
                cout << "Enter email: ";
                getline(cin, newContact.email);
                cout << "Enter phone number: ";
                cin >> newContact.phoneNumber;
                cin.ignore();
                cout << "Enter address: ";
                getline(cin, newContact.address);
                addContact(contacts, newContact);
                break;
            }
            case 2: {
                string name;
                cout << "Enter name to view details: ";
                cin.ignore();
                getline(cin, name);
                viewContactDetails(contacts, name);
                break;
            }
            case 3:
                displayAllContacts(contacts);
                break;
            case 4: {
                long long phoneNumber;
                cout << "Enter phone number to search: ";
                cin >> phoneNumber;
                searchCOntactbyNumber(contacts, phoneNumber);
                break;
            }
            case 5:
                sortContactsByName(contacts);
                break;
            case 6:
                saveContactsToFile(contacts, "contacts.csv");
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}

void addContact(vector<contact>& contacts, const contact& newContact) {
    contacts.push_back(newContact);
    cout << "Contact added successfully." << endl;
}

void viewContactDetails(const vector<contact>& contacts, const string& name) {
    auto it = find_if(contacts.begin(), contacts.end(), [&name](const contact& c) {
        return c.name == name;
    });

    if (it != contacts.end()) {
        cout << "Name: " << it->name << endl;
        cout << "Email: " << it->email << endl;
        cout << "Phone Number: " << it->phoneNumber << endl;
        cout << "Address: " << it->address << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

void loadContactsFromFile(vector<contact>& contacts, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        contact c;
        getline(ss, c.name, ',');
        getline(ss, c.email, ',');
        string phoneStr;
        getline(ss, phoneStr, ',');
        c.phoneNumber = stoll(phoneStr);
        getline(ss, c.address);
        contacts.push_back(c);
    }
    file.close();
}

void saveContactsToFile(const vector<contact>& contacts, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& c : contacts) {
        outFile << c.name << "," << c.email << "," << c.phoneNumber << "," << c.address << "\n";
    }

    outFile.close();
}

void displayAllContacts(const vector<contact>& contacts) {
    cout << "Name\t\tEmail\t\tPhone Number\t\tAddress" << endl;
    for (const auto& c : contacts) {
        cout << c.name << "\t\t" << c.email << "\t\t" << c.phoneNumber << "\t\t" << c.address << endl;
    }
}

void searchCOntactbyNumber(const vector<contact>& contacts, long long phoneNumber) {
    auto it = find_if(contacts.begin(), contacts.end(), [phoneNumber](const contact& c) {
        return c.phoneNumber == phoneNumber;
    });

    if (it != contacts.end()) {
        cout << "Contact found: " << endl;
        cout << "Name: " << it->name << endl;
        cout << "Email: " << it->email << endl;
        cout << "Phone Number: " << it->phoneNumber << endl;
        cout << "Address: " << it->address << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

void sortContactsByName(vector<contact>& contacts) {
    sort(contacts.begin(), contacts.end(), [](const contact& a, const contact& b) {
        return a.name < b.name;
    });
    cout << "Contacts sorted by name." << endl;
}
