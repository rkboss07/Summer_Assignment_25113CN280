#include <iostream>

using namespace std;

int main() {
    int n1, n2;
    cout << "Enter the size of both arrays: ";
    cin >> n1 >> n2;

    int arr1[n1], arr2[n2];
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    int merged[n1 + n2];
    for (int i = 0; i < n1; i++) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        merged[n1 + i] = arr2[i];
    }
    cout << "Merged array: ";
    for (int i = 0; i < n1 + n2; i++)
        cout << merged[i] << " ";
    cout << endl;
    return 0;
}