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
        s1.insert(arr1[i]);             // Inserting elements of the first array into the set
    }

    std::set<int> s2;
    for (int i = 0; i < n2; i++) {
        s2.insert(arr2[i]);             // Inserting elements of the second array into the set
    }

    vector<int> result;
    for (int i: s1) {
        if (s2.find(i) != s2.end()) {    // Checking if the element is present in the second set
            result.push_back(i);         // If present, add it to the result vector
        }
    }
    cout << "Intersection of the two arrays is: ";
    for (int i: result) {
        cout << i << " ";
    }
    cout << endl;
}