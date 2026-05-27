#include <iostream> 

using namespace std;


int main(){
    int n;
    cout << "Enter the no to find table of: ";
    cin >> n;

    for (int i = 1; i <= 10; i++){
        cout << n << " X " << i << " = " << n*i << endl;
    }
}