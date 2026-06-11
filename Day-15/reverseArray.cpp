#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int array[n];
    cout << "Enter the elements of the array: "<<endl;
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    cout << "Array before reversing: "<<endl;
    for (int i = 0; i < n; i++){
        cout << array[i]<< " ";
    }
    cout <<endl;

    int left = 0, right = n-1;

    while (left < right){
        int temp = array[right];
        array[right] = array[left];
        array[left] = temp;
        left++;
        right--;
    }

    cout <<"Array after reversing: "<< endl;
    for (int i = 0; i < n; i++){
        cout << array[i]<< " ";
    }
    cout<<endl;
}