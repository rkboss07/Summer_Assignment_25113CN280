#include <iostream>
#include <cmath>

using namespace std;

int digitCount(int n);
int isArmstrong(int n);



int main(){
    int n;
    cout << "Enter the range to find Armstrong Numbers upto: ";
    cin >> n;

    for (int i = 1; i <=n; i++){
        if (isArmstrong(i)){
            cout << i << endl;                       
        }
    }
}

//Function to count the number of digits in a number
int digitCount(int n){
    int digit = 0;
    while (n > 0){
        digit++;
        n/=10;
    }
    return digit;
}

//Function to check if a number is an Armstrong number or not
int isArmstrong(int n){

    int temp = n;
    int sum = 0;

    while (temp > 0){
        sum+= pow(temp%10, digitCount(n));
        temp/=10;
    }

    if (sum == n){
        return 1;
    }
    else {
        return 0;
    }
}