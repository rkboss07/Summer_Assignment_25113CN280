#include <iostream>

using namespace std;


char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

bool isUpperCase(char c) {
    return (c >= 'A' && c <= 'Z');
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    for (char c: str) {
        if (isUpperCase(c)) {
            cout << toLowerCase(c);
        } else {
            cout << c;
        }
    }
    cout << endl;
}