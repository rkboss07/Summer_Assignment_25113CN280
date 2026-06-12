#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    std::vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    std::vector<int> missingNumbers;

    for (int i=1; i<n; i++) {
        if (arr[i-1] + 1 != arr[i]) {
            missingNumbers.push_back(arr[i-1] + 1);         
        }
    }
    if (!missingNumbers.empty()) {
        cout << "Missing numbers: ";
        for (int num : missingNumbers) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No missing number found." << endl;
    }
    return 0;
}