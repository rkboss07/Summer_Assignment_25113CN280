#include <iostream>

using namespace std;

int main() {
    int n;
    cout <<"Enter the size of the Array: ";
    cin >> n;

    int array[n];
    cout<<"Enter the elements of the Array: "<<endl;
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    int rightmost = array[n-1];

    for (int i = n; i > 0; i--) {
        array[i] = array[i-1];
    }
    array[0] = rightmost;

    cout << "Array after left rotation: ";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}