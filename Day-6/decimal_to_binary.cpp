#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int decimal, binary = 0, c=0;
    cout << "Enter a Decimal no to convert to Binary: ";
    cin >> decimal;
    int temp = decimal;

    while(temp > 0) {
        binary = binary + (temp%2)*pow(10,c);
        temp/=2;
        c++;
 
 
    }

    cout << "The Binary conversion of " << decimal << " is " << binary <<endl;
}