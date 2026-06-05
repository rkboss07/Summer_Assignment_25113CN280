#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the traingle: ";
    cin >> size;
    if (size <= 0) cout << "Invalid Input"<<endl;

    for (int i = 1; i <= size; i++){        
        for (int j = 1; j <= i; j++){
            cout << (char)('A' + i - 1)<<" ";
        }
        cout<<endl;
    }

}