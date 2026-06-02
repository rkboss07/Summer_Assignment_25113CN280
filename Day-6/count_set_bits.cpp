#include <iostream>

using namespace std;

int main() {
    int number, count = 0;
    
    cout <<"Enter the number to cout set bits in: ";
    cin >> number;
    int temp = number;

    while (temp > 0){
        count+= temp & 1;
        temp >>= 1;
    }

    cout << "Number of set bits in " << number << " is " << count << endl;
}