#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count_even = 0, count_odd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count_even++;
        } else {
            count_odd++;
        }
    }
    cout << "Number of even elements: " << count_even << endl;
    cout << "Number of odd elements: " << count_odd << endl;
    return 0;
}