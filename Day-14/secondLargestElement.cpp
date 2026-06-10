#include <iostream>
#include <climits>

using namespace std;

int secondMaximum(int arr[], int n);


int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = secondMaximum(arr, n);
    if (result == INT_MIN) {
        cout << "There is no second maximum element." << endl;
    } else {
        cout << "The second maximum element is: " << result << endl;
    }
    return 0;
}


int secondMaximum(int arr[], int n) {
    int max1 = INT_MIN, max2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    return max2;
}