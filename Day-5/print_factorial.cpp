#include <iostream>

using namespace std;


int main() {
    int n;

    cout << "Enter the number to check factors of: ";
    cin >> n;


    cout << n << " = ";
    for (int i = 1; i <= n; i++){
        if (n % i == 0) cout << i ;
        if (n%i==0 && i != n) cout<< " X ";
    }
    cout << endl;
}