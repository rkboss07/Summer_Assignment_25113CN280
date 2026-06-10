#include <iostream>

using namespace std;

int countFrequency(int arr[], int n, int toSearch);

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
    cout << "Enter the element to count frequency: ";
    cin >> toSearch;

    int frequency = countFrequency(arr, n, toSearch);
    cout << "Frequency of " << toSearch << " in the array is: " << frequency << endl;

    return 0;

}

int countFrequency(int arr[], int n, int toSearch) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == toSearch) {
            count++;
        }
    }
    return count;
}