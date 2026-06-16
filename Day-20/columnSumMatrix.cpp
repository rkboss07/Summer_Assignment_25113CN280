#include <iostream>


using namespace std;

int main() {
    int m,n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    int matrix[m][n];
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    int columnSum[n] = {0};
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            columnSum[j] += matrix[i][j];
        }
    }
    cout << "The sum of each column is: " << endl;
    for (int j = 0; j < n; j++) {
        cout << "Column " << j + 1 << ": " << columnSum[j]
                << endl;
    }
    return 0;
}