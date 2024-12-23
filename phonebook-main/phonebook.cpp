#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int menu();

struct Contact {
    string name;
    string number;
};

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        choice = menu();

        if (choice == 1) {  // Add Contact
            Contact newContact;
            cout << "\t\t\t\t\t\tName: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, newContact.name); // Use getline to allow spaces in the name
            cout << "\t\t\t\t\t\tPhone No.: ";
            cin >> newContact.number;
            contacts.push_back(newContact);
            cout << "\t\t\t\t\t\tContact Added Successfully!\n";
        }
        
        else if (choice == 2) {  // Display Contacts
            if (contacts.empty()) {
                cout << "\t\t\t\t\t\tYour Contact List is Empty\n";
            } else {
                cout << "\t\t\t\t\t\t---------------------------------------------\n";
                cout << "\t\t\t\t\t\t| " << setw(20) << left << "Name" 
                     << " | " << setw(15) << left << "Phone" << " |\n";
                cout << "\t\t\t\t\t\t---------------------------------------------\n";
                for (const auto &contact : contacts) {
                    cout << "\t\t\t\t\t\t| " << setw(20) << left << contact.name
                         << " | " << setw(15) << left << contact.number << " |\n";
                }
                cout << "\t\t\t\t\t\t---------------------------------------------\n";
            }
        }
        
        else if (choice == 3) {  // Search by Number
            string searchNumber;
            cout << "\t\t\t\t\t\tNumber: ";
            cin >> searchNumber;
            bool found = false;
            for (const auto &contact : contacts) {
                if (contact.number == searchNumber) {
                    cout << "\t\t\t\t\t\tNumber Found\n";
                    cout << "\t\t\t\t\t\tName: " << contact.name
                         << "          Phone: " << contact.number << "\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\t\t\t\t\t\tThis Number is Not Found in Your Contact List\n";
            }
        }
        
        else if (choice == 4) {  // Search by Name
            string searchName;
            cout << "\t\t\t\t\t\tName: ";
            cin >> searchName;
            bool found = false;
            for (const auto &contact : contacts) {
                if (contact.name == searchName) {
                    cout << "\t\t\t\t\t\tName Found\n";
                    cout << "\t\t\t\t\t\tName: " << contact.name
                         << "          Phone: " << contact.number << "\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\t\t\t\t\t\tThis Name is Not Found in Your Contact List\n";
            }
        }
        
        else if (choice == 5) {  // Update Contact
            string searchName;
            cout << "\t\t\t\t\t\tName: ";
            cin >> searchName;
            bool found = false;
            for (auto &contact : contacts) {
                if (contact.name == searchName) {
                    cout << "\t\t\t\t\t\tNew Name: ";
                    cin >> contact.name;
                    cout << "\t\t\t\t\t\tNew Number: ";
                    cin >> contact.number;
                    cout << "\t\t\t\t\t\tContact Updated Successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\t\t\t\t\t\tThis Name is Not Found in Your Contact List\n";
            }
        }
        
        else if (choice == 6) {  // Delete Contact
            string searchName;
            cout << "\t\t\t\t\t\tFor Deletion, Enter Name: ";
            cin >> searchName;
            bool found = false;

            for (size_t i = 0; i < contacts.size(); ++i) {
                if (contacts[i].name == searchName) {
                    contacts.erase(contacts.begin() + i);
                    cout << "\t\t\t\t\t\tContact Deleted Successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\t\t\t\t\t\tThis Name is Not Found in Your Contact List\n";
            }
        }
        
        else if (choice == 7) {  // Delete All Contacts
            contacts.clear();
            cout << "\t\t\t\t\t\tAll Contacts Deleted Successfully!\n";
        }
        
        else if (choice == 8) {  // Number of Contacts
            cout << "\t\t\t\t\t\tTotal Number of Contacts: " << contacts.size() << "\n";
        }
        
        else if (choice == 9) {  // Exit
            cout << "\t\t\t\t\t\tExiting...\n";
        }
        
        else {
            cout << "\t\t\t\t\t\tInvalid Choice. Please Try Again.\n";
        }

    } while (choice != 9);

    return 0;
}

int menu() {
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t--------------------------------------\n";
    cout << "\t\t\t\t\t\t|        PHONE BOOK APPLICATION      |\n";
    cout << "\t\t\t\t\t\t--------------------------------------\n";
    cout << "\t\t\t\t\t\t|                                    |\n";
    cout << "\t\t\t\t\t\t|        [1] Add Contacts            |\n";
    cout << "\t\t\t\t\t\t|        [2] Display All Contacts    |\n";
    cout << "\t\t\t\t\t\t|        [3] Search by Number        |\n";
    cout << "\t\t\t\t\t\t|        [4] Search by Name          |\n";
    cout << "\t\t\t\t\t\t|        [5] Update                  |\n";
    cout << "\t\t\t\t\t\t|        [6] Delete                  |\n";
    cout << "\t\t\t\t\t\t|        [7] Delete All              |\n";
    cout << "\t\t\t\t\t\t|        [8] Number of Contacts      |\n";
    cout << "\t\t\t\t\t\t|                                    |\n";
    cout << "\t\t\t\t\t\t|        [9] Exit                    |\n";
    cout << "\t\t\t\t\t\t--------------------------------------\n";
    int choice;
    cout << "\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;
    system("cls");
    return choice;
}
