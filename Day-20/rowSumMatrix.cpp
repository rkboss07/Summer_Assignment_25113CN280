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
    int rowSum[m] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rowSum[i] += matrix[i][j];
        }
    }
    cout << "The sum of each row is: " << endl;
    for (int i = 0; i < m; i++) {
        cout << "Row " << i + 1 << ": " << rowSum[i]
                << endl;
    }
    return 0;
}