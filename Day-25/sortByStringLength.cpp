#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int size;
    cout << "Enter the number of strings: ";
    cin >> size;
    vector<string> strings(size);
    cout << "Enter the strings:\n";
    for (int i = 0; i < size; i++) {
        cin >> strings[i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strings[j].size() > strings[j + 1].size()) {
                swap(strings[j], strings[j + 1]);
            }
        }
    }

    cout << "Sorted strings by length:\n";
    for (const auto& s : strings) {
        cout << s << "\n";
    }
}