#include <iostream>

using namespace std;

int main() {
    int height;

    cout << "Enter the vertical height of the pyramid: ";
    cin >> height;

    int row = height;
    int column = 2*height - 1;

    for (int i = 1; i <= row; i++){

        for (int j = 1; j <= column; j++){
            
            if (i+j <= row || j-i >= row){
                cout<<"  ";
            }
            else {
                if (j < row){
                    cout << char('A' + i+j-row-1)<<" ";
                }
                else {
                    cout << char('A' + row + i - j-1)<<" ";
                }
            }
        }
        cout <<endl;
    }
}