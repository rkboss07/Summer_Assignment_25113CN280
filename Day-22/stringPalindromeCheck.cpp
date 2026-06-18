#include <iostream>

using namespace std;


// Function to check if a character is uppercase
bool isUpperCase(char c) {
    return c >= 'A' && c <= 'Z';
}


// Function to convert a character to lowercase
char toLowerCase(char c) {
    if (isUpperCase(c)) {
        return c + ('a' - 'A');
    }
    return c;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int n = s.length();
    bool isPalindrome = true;
    for (int i = 0; i < n / 2; i++) {
        if (toLowerCase(s[i]) != toLowerCase(s[n - 1 - i])) {              //Case-insensitive comparison
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}