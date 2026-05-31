#include <iostream>
#include <cmath>

using namespace std;

int digitCount(int n);
int main(){
    int n, temp;
    cout << "Enter a number to check if it is Armstrong number: ";
    cin >> n;

    temp = n;
    int sum = 0;

    while (temp > 0){
        sum+= pow(temp%10, digitCount(n));
        temp/=10;
    }

    if (sum == n){
        cout << n << " is an armstrong number"<<endl; 
    }
    else {
        cout << n << " is not an armstrong number." <<endl;
    }
}



int digitCount(int n){
    int digit = 0;
    while (n > 0){
        digit++;
        n/=10;
    }
    return digit;
}