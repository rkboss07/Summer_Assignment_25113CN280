#include <iostream>

using namespace std;

int main(){
    int n, sum = 0;
    cout << "Enter the no of terms to add: ";
    cin >>  n;

    for (int i = 1; i <= n ; i++){
        sum+= i;
    }

    cout << "Sum of " << n << " terms "<< "is: " << sum << endl;
}