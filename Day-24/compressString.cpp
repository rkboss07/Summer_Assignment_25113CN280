#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string s2 = "";

    int count = 0;

     for (int i = 1; i <= s.length(); i++) {
        if (i < s.length() && s[i] == s[i - 1]) {
            count++;
        } else {
            s2 += s[i - 1];

            if (count > 1)
                s2 += to_string(count);

            count = 1;
        }
    }
    cout << "Compressed string: " << s2 << endl;
}