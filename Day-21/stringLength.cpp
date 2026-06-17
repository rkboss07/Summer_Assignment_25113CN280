#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    cout << "Length of the string: " << length << endl;
    
}