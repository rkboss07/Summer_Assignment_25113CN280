#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1;
    cout << "Enter a string: ";
    cin >> s1;

    string s2;
    cout<< "Enter the string to check if it is a rotation of the first string: ";
    cin >> s2;
    
    if (s1.length() != s2.length()) {
        cout << s2 << " is not a rotation of " << s1 << endl;
        return 0;
    }

    s1 += s1;
    if (s1.find(s2) != string::npos) {
        cout << s2 << " is a rotation of " << s1.substr(0, s1.length() / 2) << endl;
    } else {
        cout << s2 << " is not a rotation of " << s1.substr(0, s1.length() / 2) << endl;
    }
}