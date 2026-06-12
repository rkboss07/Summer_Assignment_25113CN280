#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
     std::sort(arr.begin(), arr.end());
    int left = 0;
    for (int right = 1; right < n; right++) {
        if (arr[left] != arr[right]) {
            left++;
            arr[left] = arr[right];
        }
    }
    arr.erase(arr.begin() + left + 1, arr.begin() + n);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}