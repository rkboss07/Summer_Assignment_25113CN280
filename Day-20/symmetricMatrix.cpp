#include <iostream>

using namespace std;

int main() {
    int m,n;
    cout << "Enter the dimensions of the matrix (m n): ";
    cin >> m >> n;

    int matrix[m][n];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]  != matrix[j][i]) {
                cout << "The matrix is not symmetric." << endl;
                return 0;
            }
        }
    }
    cout << "The matrix is symmetric." << endl;
    return 0;
}