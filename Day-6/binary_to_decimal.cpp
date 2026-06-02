#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int binary, decimal = 0, c = 0;
    
    cout << "Enter a binary number to convert to a decimal number: ";
    cin >> binary;
    int temp = binary;
    while (temp > 0){
        if (temp % 10 != 0 && temp % 10 != 1){
            cout << "Invalid binary number. Please enter a valid binary number." << endl;
            return 1;
        }
        decimal = (temp%10)*pow(2,c);
        temp/=10;
        c++;
    }
    cout << "The decimal conversion of the binary number " << binary << " is " << decimal<<endl;
}