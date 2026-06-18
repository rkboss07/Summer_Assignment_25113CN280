#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int frequencyofCharacter(string str, char c) {
    unordered_map<char, int> freqMap;
    for (char ch : str) {
        freqMap[tolower(ch)]++;
    }
    if (freqMap.count(tolower(c)) == 0) return 0;
    return freqMap[tolower(c)];
}


int main() {
    string str;
    char c;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Enter a character to find its frequency: ";
    cin >> c;

    int frequency = frequencyofCharacter(str, tolower(c));
    cout << "The frequency of '" << c << "' in the string is: " << frequency << endl;
}

// This program is case Insenstive and counts frequeny of for example 'R' and 'r' as same character.