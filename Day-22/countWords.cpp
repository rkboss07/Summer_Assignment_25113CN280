#include <iostream>

using namespace std;


int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    int countWords = 1;

    for (char c: s){
        if (c == ' ') countWords++;
    }
    cout << "The number of words in the sentence is: "<< countWords<<endl;

}