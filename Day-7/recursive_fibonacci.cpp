#include <iostream>

using namespace std;

int fibonacci(int n) {
    if ( n <= 1) {
        return n;
    }
    return (fibonacci(n-1)+fibonacci(n-2));
}

int main() {
    int n;
    cout << "Enter the terms upto find you want to find the fibonnaci series: ";
    cin >> n;

    if (n < 0) {
        cout << "Enter a valid input" << endl;
        return 1;
    }
    cout << "Fibonacci Series upto "<< n <<": "<< endl;
    for (int i = 0; i < n; i++){
        cout << fibonacci(i) << "  ";
    }
    cout<< endl;

}