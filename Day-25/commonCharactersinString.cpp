#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> charCount;

    string s1;
    cout << "Enter the first string: ";
    cin >> s1;

    string s2;
    cout << "Enter the second string: ";
    cin >> s2;

    for (char c: s1) {
        charCount[c]++;
    }

    cout << "Common characters in both strings: ";
    for (char c: s2) {
        if (charCount[c] > 0) {
            cout << c << " ";
            charCount.erase(c);
        }
    }
    cout << endl;
}