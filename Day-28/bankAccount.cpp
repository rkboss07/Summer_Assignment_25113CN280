#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct account {
    long long accountNumber;
    string accountHolderName;
    double balance;
    vector<double> transactionHistory;
    string email;
    long long phoneNumber;
};
// Function prototypes
void createAccount(vector<account>& accounts);
void viewAccountDetails(vector<account>& accounts, long long accountNumber);
void deposit(vector<account>& accounts, long long accountNumber, double amount);
void withdraw(vector<account>& accounts, long long accountNumber, double amount);
void printStatement(vector<account>& accounts, long long accountNumber);
void saveAccountsToFile(const vector<account>& accounts, const string& filename);


int main() {
    vector<account> accounts;
    int choice;
    long long accountNumber;
    double amount;
    ifstream file("accounts.csv");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string cell;
            account acc;
            istringstream iss(line);
            getline(iss, cell, ',');
            acc.accountNumber = stoll(cell);

            getline(iss, acc.accountHolderName, ',');

            getline(iss, cell, ',');
            acc.balance = stod(cell);

            getline(iss, acc.email, ',');

            getline(iss, cell, ',');
            acc.phoneNumber = stoll(cell);

            string history;
            getline(iss, history);

            if (!history.empty() && history.front() == '"')
                history.erase(0, 1);

            if (!history.empty() && history.back() == '"')
                history.pop_back();

            stringstream txStream(history);
            string transaction;

            while (getline(txStream, transaction, ',')) {
                if (!transaction.empty()) {
                    acc.transactionHistory.push_back(stod(transaction));
                }
            }

            accounts.push_back(acc);

        }
        file.close();
    }

    do {
        cout << "Bank Account Management System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. View Account Details" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Print Statement" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(accounts);
                saveAccountsToFile(accounts, "accounts.csv");
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                viewAccountDetails(accounts, accountNumber);
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                deposit(accounts, accountNumber, amount);
                saveAccountsToFile(accounts, "accounts.csv");
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                withdraw(accounts, accountNumber, amount);
                saveAccountsToFile(accounts, "accounts.csv");
                break;
            case 5:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                printStatement(accounts, accountNumber);
                break;
            case 6:
                saveAccountsToFile(accounts, "accounts.csv");
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

bool accountExists(const vector<account>& accounts,
                   long long accountNumber)
{
    return any_of(accounts.begin(),
                  accounts.end(),
                  [accountNumber](const account& acc)
                  {
                      return acc.accountNumber == accountNumber;
                  });
}

void viewAccountDetails(vector<account>& accounts, long long accountNumber) {
    auto it = find_if(accounts.begin(), accounts.end(), [accountNumber](const account& acc) {
        return acc.accountNumber == accountNumber;
    });

    if (it != accounts.end()) {
        cout << "Account Number: " << it->accountNumber << endl;
        cout << "Account Holder Name: " << it->accountHolderName << endl;
        cout << "Balance: $" << it->balance << endl;
        cout << "Transaction History:" << endl;
        cout << "Email: " << it->email << endl;
        cout << "Phone Number: " << it->phoneNumber << endl;
        for (const auto& transaction : it->transactionHistory) {
            cout << transaction << endl;
        }
    } else {
        cout << "Account not found." << endl;
    }
    
}

void createAccount(vector<account>& accounts) {
    account newAccount;
    cout << "Enter Account Number: ";
    cin >> newAccount.accountNumber;
    cout << "Enter Account Holder Name: ";
    cin.ignore(); 
    getline(cin, newAccount.accountHolderName);
    cout << "Enter Email: ";
    getline(cin, newAccount.email);
    cout << "Enter Phone Number: ";
    cin >> newAccount.phoneNumber;
    newAccount.balance = 0.0;
    if (accountExists(accounts, newAccount.accountNumber)) {
        cout << "Account with this number already exists." << endl;
        return;
    }
    accounts.push_back(newAccount);
    cout << "Account created successfully!" << endl;
}

void deposit(vector<account>& accounts, long long accountNumber, double amount) {
    if (amount <= 0) {
        cout << "Invalid amount.\n";
        return;
    }
    auto it = find_if(accounts.begin(), accounts.end(), [accountNumber](const account& acc) {
        return acc.accountNumber == accountNumber;
    });

    if (it != accounts.end()) {
        it->balance += amount;
        it->transactionHistory.push_back(amount);
        cout << "Deposit successful! New Balance: $" << it->balance << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

void withdraw(vector<account>& accounts, long long accountNumber, double amount) {
    if (amount <= 0) {
        cout << "Invalid amount.\n";
        return;
    }
    auto it = find_if(accounts.begin(), accounts.end(), [accountNumber](const account& acc) {
        return acc.accountNumber == accountNumber;
    });

    if (it != accounts.end()) {
        if (it->balance >= amount) {
            it->balance -= amount;
            it->transactionHistory.push_back(-amount);
            cout << "Withdrawal successful! New Balance: $" << it->balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    } else {
        cout << "Account not found." << endl;
    }
}

void printStatement(vector<account>& accounts, long long accountNumber) {
    auto it = find_if(accounts.begin(), accounts.end(), [accountNumber](const account& acc) {
        return acc.accountNumber == accountNumber;
    });

    if (it != accounts.end()) {
        cout << "Account Statement for Account Number: " << it->accountNumber << endl;
        cout << "Account Holder Name: " << it->accountHolderName << endl;
        cout << "Balance: $" << it->balance << endl;
        cout << "Transaction History:" << endl;
        for (const auto& transaction : it->transactionHistory) {
            cout << transaction << endl;
        }
    } else {
        cout << "Account not found." << endl;
    }
}

void saveAccountsToFile(const vector<account>& accounts, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& acc : accounts) {
            outFile << acc.accountNumber << ","
            << acc.accountHolderName << ","
            << acc.balance << ","
            << acc.email << ","
            << acc.phoneNumber << ",\"";

        for(size_t i = 0; i < acc.transactionHistory.size(); i++) {

            outFile << acc.transactionHistory[i];

            if(i + 1 < acc.transactionHistory.size())
                outFile << ",";
            
        }

        outFile << "\"\n";

    }

    outFile.close();
}
