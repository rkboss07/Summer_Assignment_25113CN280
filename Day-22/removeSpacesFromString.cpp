#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    for (int i = 0; i < s.length(); i++){
        if (s[i] == ' ') s.erase(i, 1);
    }
    cout << "Sentence without spaces: " << s << endl;
}