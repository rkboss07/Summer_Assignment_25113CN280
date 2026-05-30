#include <iostream>

using namespace std;


#define MIN(a,b) ((a) < (b) ? (a): (b));
int GCD(int num1, int num2);

int main () {
    int num1, num2;
    cout << "Enter the two numbers to find LCM: ";
    cin >> num1 >> num2;
    int LCM = (num1*num2)/GCD(num1,num2);
    
    cout << "LCM = "<< LCM << endl; 

    return 0;

    
}

int GCD(int num1, int num2){
    int min = MIN(num1,num2);

    for (int i = min; i > 0; i--){
        if (num1 % i == 0 && num2 % i == 0){
            return i;      
        }
    }
    return 1;
}