#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> array1;
    int size1;
    cout << "Enter the size of the first array: ";
    cin >> size1;
    cout << "Enter the elements of the first sorted array: ";
    for (int i = 0; i < size1; i++) {
        int value;
        cin >> value;
        array1.push_back(value);
    }

    vector<int> array2;
    int size2;
    cout << "Enter the size of the second array: ";
    cin >> size2;
    cout << "Enter the elements of the second sorted array: ";
    for (int i = 0; i < size2; i++) {
        int value;
        cin >> value;
        array2.push_back(value);
    }

    vector<int> mergedArray;
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (array1[i] < array2[j]) {
            mergedArray.push_back(array1[i]);
            i++;
        } else {
            mergedArray.push_back(array2[j]);
            j++;
        }
    }
    
    //Adding remaining elements from array1 or array2 if any
    while (i < size1) {
        mergedArray.push_back(array1[i]);
        i++;
    }
    while (j < size2) {
        mergedArray.push_back(array2[j]);
        j++;
    }

    cout << "Merged sorted array: ";
    for (int k = 0; k < mergedArray.size(); k++) {
        cout << mergedArray[k] << " ";
    }
    cout << endl;

    return 0;
}