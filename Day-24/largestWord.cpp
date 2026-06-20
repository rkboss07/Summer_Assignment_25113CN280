#include <iostream>

using namespace std;


int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    int maxWordLength = 0;
    int currentWordLength = 0;

    for(char c: s){
        if (c == ' '){
            currentWordLength = 0;
        }
        else{
            currentWordLength++;
            if (currentWordLength > maxWordLength){
                maxWordLength = currentWordLength;
            }
        }
    }
    cout << "The length of the largest word is: " << maxWordLength << endl;
}