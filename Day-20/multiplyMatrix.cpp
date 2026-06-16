#include <iostream>

using namespace std;

int main() {
    int m1,n1
    cout << "Enter the dimension of the first matrix: ";
    cin >> m1 >> n1;


    int m2,n2;
    cout << "Enter the dimension of first matrix: ";
    cin >> m2 >> n2;

    if (n1!=m2){
        cout << "Matrix Multiplication not possible "<<endl;
        return 1;
    }
    int A[m1][n1], B[m2][n2], C[m1][n2];
    cout << "Enter the elements of first matrix"<<endl;
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Enter the elements of second matrix"<<endl;
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n2; j++){
            int sum = 0;
            for (int k = 0; k < n1; k++){
                sum+= A[i][k] * B[k][j];
            }
        }
    }
}