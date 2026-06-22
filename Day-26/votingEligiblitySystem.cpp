#include <iostream>

using namespace std;

int main() {
    int choice;
    cout << "Check Voting Eligibility" << endl
         << "1. Check eligiblity by age" << endl
         << "2. Check eligiblity by date of birth" << endl
         << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int age;
        cout << "Enter your age: ";
        cin >> age;

        if (age >= 18) {
            cout << "You are eligible to vote." << endl;
        } else {
            cout << "You are not eligible to vote." << endl;
        }
    } else if (choice == 2) {
        int day, month, year;
        cout << "Enter your date of birth (DD MM YYYY): ";
        cin >> day >> month >> year;

        // Assuming the current date is 1st January 2026 for eligibility check
        int currentDay = 1, currentMonth = 1, currentYear = 2026;

        if ((currentYear - year > 18) || 
            (currentYear - year == 18 && currentMonth > month) || 
            (currentYear - year == 18 && currentMonth == month && currentDay >= day)) {
            cout << "You are eligible to vote." << endl;
        } else {
            cout << "You are not eligible to vote." << endl;
        }
    } else {
        cout << "Invalid choice. Please select either 1 or 2." << endl;
    }
    return 0;
}