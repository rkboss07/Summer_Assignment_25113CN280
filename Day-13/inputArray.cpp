#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int array[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        array[i] = num;
    }
    cout << "The elements of the array are: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}