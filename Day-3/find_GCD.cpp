#include <iostream>

using namespace std;


#define MIN(a,b) ((a) < (b) ? (a): (b));

int main () {
    int num1, num2;
    cout << "Enter the two numbers to find GCD: ";
    cin >> num1 >> num2;


    int min = MIN(num1,num2);

    for (int i = min; i > 0; i--){
        if (num1 % i == 0 && num2 % i == 0){
            cout << "GCD is: " << i << endl;
            break;
        }
    }
}