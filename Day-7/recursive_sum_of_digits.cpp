#include <iostream>


using namespace std;


int sum_of_n(int n){
    if (n==0) return 0;

    return(n%10+sum_of_n(n/10));
}

int main() {
    int number;
    cout << "Enter the number to find sum of digits of: ";
    cin >> number;
    if (number < 0){
        cout << "Enter a Positive number."<<endl;
        return 1;
    }

    cout << "The sum of digits in "<<number<<" is: "<< sum_of_n(number)<<endl;
}