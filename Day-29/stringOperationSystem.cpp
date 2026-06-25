#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//function prototypes
void sortbyCharacter(string &str);
void findLengthOfString(const string &str);
void characterFrequency(const string &str, char ch);
void reverseString(string &str);
void checkPalindrome(const string &str);


int main() {
    int choice;
    string str;
    cout << "Enter a string: ";
    cin >> str;
    do {
        cout << "\nMenu:\n";
        cout << "1. Sort by Character\n";
        cout << "2. Find Length of String\n";
        cout << "3. Character Frequency\n";
        cout << "4. Reverse String\n";
        cout << "5. Check Palindrome\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                sortbyCharacter(str); 
                cout << "Sorted string: " << str << endl;
                break;
            case 2:
                findLengthOfString(str);
                break;
            case 3:
                char ch;
                cout << "Enter character to find frequency: ";
                cin >> ch;
                characterFrequency(str, ch);                  
                break;
            case 4:
                reverseString(str);
                cout << "Reversed string: " << str << endl;
                break; 
            case 5:
                checkPalindrome(str);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

}

void sortbyCharacter(string &str) {
    sort(str.begin(), str.end());
}

void findLengthOfString(const string &str) {
    cout << "Length of the string: " << str.length() << endl;
}

void characterFrequency(const string &str, char ch) {
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }
    cout << "Frequency of character '" << ch << "': " << count << endl;
}

void reverseString(string &str) {
    reverse(str.begin(), str.end());
}

void checkPalindrome(const string &str) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    if (str == reversedStr) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
}