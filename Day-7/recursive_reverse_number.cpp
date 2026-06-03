#include <iostream>

using namespace std;

int reverse(int n, int rev=0) {
    if (n==0) return rev;
    return reverse(n/10, rev*10 + n%10);
}

int main() {
    int number;
    cout << "Enter the number to reverse: ";
    cin >> number;
    if (number < 0){
        cout << "Enter a Positive number."<<endl;
        return 1;
    }

    cout << "The reverse of "<<number<<" is: "<< reverse(number)<<endl;
}