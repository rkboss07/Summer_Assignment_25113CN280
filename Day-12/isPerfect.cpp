#include <iostream>

using namespace std;

bool isPerfectNumber(int num);


int main() {
    int num;
    cout << "Enter a number to check if it is a perfect number: ";
    cin >> num;
    if (isPerfectNumber(num)) {
        cout << num << " is a perfect number." << endl;
    } else {
        cout << num << " is not a perfect number." << endl;
    }
    return 0;

}

//Checking if a number is a perfect number
bool isPerfectNumber(int num){
    if (num <= 1) return false; 
    int sum = 1; 
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}