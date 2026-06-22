#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Function prototypes
void deposit (int& balance, int amount, vector<int>& prevtransactions);
void PINVerification (int PIN, int inputPIN, int& attempts);
void withdraw (int& balance, int amount, vector<int>& prevtransactions);
void statement (vector<int>& prevtransactions, int balance);
void changePIN (int& PIN, int newPIN);

// Account structure to hold account information
struct accountInfo{
    int accNo, PIN, balance;
    vector<int> prevtransactions;
};



int main() {
    vector<accountInfo> accounts = {
        {123456, 1234, 1000, {}},
        {654321, 4321, 500, {}},
        {111111, 1111, 2000, {}}
    };

    while (true) {
        int accNo, inputPIN, attempts = 0;
        cout << "Enter your Account Number: ";
        cin >> accNo;

        auto it = find_if(accounts.begin(), accounts.end(), [accNo](const accountInfo& acc) {
            return acc.accNo == accNo;
        });

        if (it == accounts.end()) {
            cout << "Account not found. Please try again." << endl;
            continue;
        }

        while (attempts < 3) {
            cout << "Enter your PIN: ";
            cin >> inputPIN;
            PINVerification(it->PIN, inputPIN, attempts);
            if (it->PIN == inputPIN) break;
        }

        if (attempts == 3) {
            cout << "Too many incorrect attempts. Exiting." << endl;
            break;
        }

        int choice;
        cout << "1. Deposit" << endl
             << "2. Withdraw" << endl
             << "3. Statement" << endl
             << "4. Change PIN" << endl
             << "5. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(it->balance, amount, it->prevtransactions);
                break;
            }
            case 2: {
                int amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(it->balance, amount, it->prevtransactions);
                break;
            }
            case 3:
                statement(it->prevtransactions, it->balance);
                break;
            case 4: {
                int newPIN;
                cout << "Enter new PIN: ";
                cin >> newPIN;
                changePIN(it->PIN, newPIN);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

//Function definitions


void deposit (int& balance, int amount, vector<int>& prevtransactions){
    cout << "Deposited "<<amount<<" to the Account"<<endl;
    prevtransactions.push_back(amount);
    balance+=amount;
    cout << "New Balance: "<<balance<<endl;
}

void PINVerification (int PIN, int inputPIN, int& attempts){
    if (PIN == inputPIN) cout << "PIN Verified Successfully!"<<endl;
    else{
        cout << "Incorrect PIN. Please try again."<<endl;
        attempts++;
    }
}

void withdraw (int& balance, int amount, vector<int>& prevtransactions){
    if (amount > balance)cout << "Not Enough Balance in the Account"<<endl;
    else {
        cout << "Withdrew "<<amount<<" from the Account"<<endl;
        prevtransactions.push_back(-amount);
        balance-=amount;
        cout << "New Balance: "<<balance<<endl;
    }
}

void statement (vector<int>& prevtransactions, int balance){
    cout << "Previous Transactions: "<<endl;
    for (int i = 0; i < prevtransactions.size(); i++){
        if (prevtransactions[i] > 0) cout << "Deposited: "<<prevtransactions[i]<<endl;
        else cout << "Withdrew: "<<-prevtransactions[i]<<endl;
    }
    cout << "Current Balance: "<<balance<<endl;
}

void changePIN (int& PIN, int newPIN){
    PIN = newPIN;
    cout << "PIN changed successfully!"<<endl;
}