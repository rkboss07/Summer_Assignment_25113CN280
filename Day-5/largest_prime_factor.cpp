#include <iostream>

using namespace std;

int check_prime(int n);

int main() {
    int n;
    cout << "Enter the number to check largest prime factor of: ";
    cin >> n;
    int largest_prime_factor = -1;
    for (int i = n; i > 1; i--){
        if (n % i == 0 && check_prime(i)){
            largest_prime_factor = i;
            break;
        }
     }
     if (largest_prime_factor != -1) cout << "The largest prime factor of " << n << " is " << largest_prime_factor << "." << endl;
}


int check_prime(int n){
    if (n <= 1) return 0;
    if (n <= 2) return 1;
    for (int i = 2; i < n; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}