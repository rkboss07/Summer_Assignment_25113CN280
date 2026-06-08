#include <iostream>
#include <cmath>

using namespace std;

bool isArmstrongNumber(int num);

int main() { 
    int num;
    cout << "Enter a number to check if it is an Armstrong number: ";
    cin >> num;
    if (isArmstrongNumber(num)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }
    return 0;
}

//Checking if a number is an Armstrong number
bool isArmstrongNumber(int num){
    if (num < 0) return false; // Negative numbers cannot be Armstrong numbers
    else if (num == 0) return true; // 0 is an Armstrong number
    int originalNum = num, sum = 0, numDigits = log10(num) + 1;
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, numDigits);
        num /= 10;
    }
    return sum == originalNum;
}
