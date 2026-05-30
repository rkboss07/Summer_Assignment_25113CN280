#include <iostream>

using namespace std;

int main () {
    int num1, num2;
    cout << "Enter the two numbers to find LCM of: ";
    cin >> num1 >> num2;

    int divisor = 2 , LCM = 1;

    while (num1 > 1 || num2 > 1) {

        if (num1 % divisor == 0 || num2 % divisor == 0) {

            if (num1 % divisor == 0)
                num1 /= divisor;

            if (num2 % divisor == 0)
                num2 /= divisor;

            LCM *= divisor;
        }
        else {
            divisor++;
        }
    }


    cout << "LCM = " << LCM << endl;
}