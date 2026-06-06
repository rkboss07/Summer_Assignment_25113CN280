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
                    cout << i+j-row<<" ";
                }
                else {
                    cout << row + i - j<<" ";
                }
            }
        }
        cout <<endl;
    }
}