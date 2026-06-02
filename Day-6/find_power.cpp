#include <iostream>

using namespace std;

int main () {
    int number, result = 1, power;
    cout << "Enter base number: ";
    cin >> number;

    cout << "Enter the power: ";
    cin >> power;

    for (int i = 0; i < power; i++){
        result*=number;
    }

    cout << number <<"^"<<power<< " = "<<result<<endl;
}