#include <iostream>
#include <unordered_set>

using namespace std;


int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    unordered_set<char> uniqueChars;

    string ans = "";
    for (char c : s) {
        if (uniqueChars.find(tolower(c)) == uniqueChars.end()) {
            uniqueChars.insert(tolower(c));
            ans += c;
        }
    }

    cout << "String after removing duplicates: " << ans << endl;

    return 0;
}