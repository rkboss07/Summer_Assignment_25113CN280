#include <iostream>

using namespace std;

int main() {
    int n, rev = 0;

    cout << "Enter the number to find reverse of: ";
    cin >> n;

    int temp = n;

    while(temp > 0){
        rev = rev*10 + temp%10;
        temp/=10;
    }
    if (n == rev){
        cout << "The entered number is palindrome" <<endl;
    }
    else {
        cout << "The entered number is not a palindrome"<< endl;
    }
    
}
