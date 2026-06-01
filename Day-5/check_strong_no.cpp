#include <iostream>

using namespace std;

int factorial(int n);

int main() {
    int n, sum = 0;
    cout  << "Enter a positive integer: ";
    cin >> n;
    int temp = n;
    while (temp > 0){
        sum += factorial(temp%10);
        temp/=10;
    }
    if (n == sum) cout << n << " is a perfect number."<<endl;
    else cout << n << " is not a perfect number."<<endl;
    
}


int factorial(int n){
    if (n == 1 || n == 0) return 1;
    int fact = n * factorial(n-1);
    return fact;
}
