#include <iostream>

using namespace std;


int factorial(int n) {
    if (n==0 || n == 1) return 1;

    return(n*factorial(n-1));
}


int main() {
    int n;
    cout << "Enter the no to find factorial of: ";
    cin >> n;

    if (n < 0){
        cout << "Factorial of negative number is not possible."<<endl;
        return 1;
    }

    int fact = factorial(n);

    cout << n <<"! = "<<fact<<endl;
    
}