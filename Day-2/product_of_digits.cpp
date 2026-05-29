#include <iostream>

using namespace std;

int main(){
    int n, product = 1;

    cout <<"Enter the number: ";
    cin >> n;

    while (n > 0){
        product*= n%10;
        n/=10;
    }

    cout<<"Product of the digits is: " << product << endl;
}