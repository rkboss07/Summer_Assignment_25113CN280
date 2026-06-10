#include <iostream>


using namespace std;
int linearSearch(int arr[], int n, int toSearch);

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int toSearch;
    cout << "Enter the element to search: ";
    cin >> toSearch;

    int result = linearSearch(arr, n, toSearch);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {        
        cout << "Element not found in the array." << endl;
    }
    return 0;
}

int linearSearch(int arr[], int n, int toSearch) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == toSearch) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}