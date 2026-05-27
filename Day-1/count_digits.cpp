#include <iostream>

using namespace std;

int main(){
    int c = 0, n,temp;

    cout << "Enter the number: ";
    cin >> n;
    temp = n;

    while(temp!=0){
        c++;
        temp/=10;
    }

    cout << "The no of digits in " << n << " is " << c << endl;
}