#include <iostream>

using namespace std;

int main() {
    int m,n;
    cout << "Enter the number of rows and columns of both matrices: ";
    cin >> m >> n;

    int matrixA[m][n], matrixB[m][n], sum[m][n];

    cout << "Enter the elements of the first matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Enter the elements of the second matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrixB[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "The sum of the two matrices is:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}