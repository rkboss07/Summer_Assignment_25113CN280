#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    
    int vowelCount = 0, consonantCount = 0, nonAlphaCount = 0;
    for (char c : str) {
        if (isalpha(c)) {
            char lowerC = tolower(c);
            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
                vowelCount++;
            } else {
                consonantCount++;
            }
        }
        else {
            nonAlphaCount++;
        }
    }
    cout << "Vowels: " << vowelCount << endl;
    cout << "Consonants: " << consonantCount << endl;
    cout << "Non-alphabetic characters: " << nonAlphaCount << endl;
    return 0;
}