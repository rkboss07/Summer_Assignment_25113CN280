#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    int size;
    cout << "Enter the number of strings: ";
    cin >> size;
    vector<string> strings(size);

    cout << "Enter the strings: ";
    for (int i = 0; i < size; i++) {
        string str;
        cin >> str;
        strings[i] = str;
    }

    // Sort the strings in ascending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strings[j] > strings[j + 1]) {
                swap(strings[j], strings[j + 1]);
            }
        }
    }

    // Display the sorted strings
    cout << "Sorted strings: ";
    for (int i = 0; i < size; i++) {
        cout << strings[i] << " ";
    }
    cout << endl;

    return 0;
}