#include <iostream>

using namespace std;

int main() {
    int n; 
    cout << "Enter the size of the Array: ";
    cin >> n;
    cout<<"Enter the elements of the Array: "<<endl;
    int array[n];
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    int left = 0;
    for (int right = 0; right < n; right++){
        if (array[right]!=0){
            int temp = array[right];
            array[right] = array[left];
            array[left] = temp;
            left++;
        }
    }
    
    cout << "Array after moving zeores to the end: "<<endl;
    for (int i = 0; i < n; i++){
        cout << array[i]<< " ";
    }
    cout << endl;

}
