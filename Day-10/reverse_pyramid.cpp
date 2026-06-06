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
            
            if (i-j >= 1 || j+i >= column + 2){
                cout<<"  ";
            }
            else {
                cout << "* ";
            }
        }
        cout <<endl;
    }
}