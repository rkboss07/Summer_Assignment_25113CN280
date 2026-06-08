#include <iostream>

using namespace std;

int fibonacci(int n);


int main() {
    int n;
    cout << "Enter the position in the Fibonacci sequence: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << endl;
    return 0;
}

//Calculating the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}
