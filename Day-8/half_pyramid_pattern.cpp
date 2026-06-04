#include <iostream>

using namespace std;

int main() {
    int size;
    cout <<"Enter the size of the Pyramid: ";
    cin>>size;
    if (size <=0){
         cout << "Invalid Size"<<endl; 
         return 0;
    }
    for (int i = 1; i<= size; i++){
        for (int j = 1; j <= size; j++){
            if (i+j <= size) cout << "  ";
            else cout << "# ";
        }
        cout <<endl;
    }
}