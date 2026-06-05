#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the traingle: ";
    cin >> size;
    if (size <= 0) cout << "Invalid Input"<<endl;

    for (int i = size; i > 0; i--){
        for (int j = 0; j < i; j++){
            cout << "* ";
        }
        cout<<endl;
    }

}