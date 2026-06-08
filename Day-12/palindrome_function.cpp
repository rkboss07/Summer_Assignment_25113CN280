#include <iostream>

using namespace std;

bool isStringPalindrome(string s);
bool isNumberPalindrome(int num);

int main() {
    int option,num;
    string str;
    cout << "Enter 1 to check if a string is a palindrome or 2 to check if a number is a palindrome: ";
    cin >> option;
    if (option == 1) {
        cout << "Enter a string: ";
        cin >> str;
        if (isStringPalindrome(str)) {
            cout << str << " is a palindrome." << endl;
        } else {
            cout << str << " is not a palindrome." << endl;
        }
    } else if (option == 2) {
        cout << "Enter a number: ";
        cin >> num;
        if (isNumberPalindrome(num)) {
            cout << num << " is a palindrome." << endl;
        } else {
            cout << num << " is not a palindrome." << endl;
        }
    }
    else {
        cout << "Invalid option." << endl;
    }
    return 0;
}

//Checking if a string is a palindrome (case-insensitive)
bool isStringPalindrome(string s){
    int left=0,right=s.size()-1;

    while(left < right){
        if (toupper(s[left]) != toupper(s[right])) return false;
        left++;
        right--;
    }
    return true;
}
//Checking if a number is a palindrome
bool isNumberPalindrome(int num){
    string s = to_string(num);
    return isStringPalindrome(s);
}