#include <iostream>

using namespace std;


int isPrime(int n);

int main() {
    int n;
    cout << "Enter the no to print Prime Numbers upto: ";;
    cin >> n;

    for (int i = 2; i <= n; i++){
        if (isPrime(i)){
            cout << i << endl;
        }
    }

}

// Check Prime No function
int isPrime (int n){     

    if (n==2) return 1;  
    else if (n < 0) return 0;    
    
    else {
        for (int i = 2; i < n; i++){
            if (n % i == 0) return 0;
        }
    }
    return 1;
}