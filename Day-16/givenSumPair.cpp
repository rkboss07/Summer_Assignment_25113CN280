#include <iostream>
#include <unordered_map>

using namespace std;

int main () {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target number: ";
    cin >> target;

    unordered_map<int, int> complementMap;
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (complementMap.count(complement)) {
            cout << "Pair found: " << arr[i] << " and " << complement << endl;
            return 0;
        }
        complementMap[arr[i]] = i;
    }
    cout << "No pair found." << endl;
    return 0;
}