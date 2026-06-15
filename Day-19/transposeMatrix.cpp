#include <iostream>

using namespace std;

int main() {
    int m, n;
    cout << "Enter the number of rows (m) and columns (n): ";
    cin >> m >> n;

    int matrix[m][n], transpose[n][m];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }


    cout << endl << "The transpose of the matrix is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transpose[i][j] = matrix[j][i];
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}