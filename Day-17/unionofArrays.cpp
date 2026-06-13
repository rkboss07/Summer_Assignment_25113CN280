#include <iostream>
#include <set>
#include <vector>


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
    std::set<int> s1;
    for (int i = 0; i < n1; i++) {
        s1.insert(arr1[i]);
    }
    for (int i = 0; i < n2; i++) {
        s1.insert(arr2[i]);
    }
    vector<int> result;
    for (int i: s1) {
        result.push_back(i);
    }
    cout << "Union of arrays: ";
    for (int i: result) {
        cout << i << " ";
    }
    cout << endl;
}

