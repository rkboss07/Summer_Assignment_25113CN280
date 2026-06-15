#include <iostream>

using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    int matrix[n][m];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum+= matrix[i][i];
    }
    cout << "Sum of diagonal elements: " << sum << endl;
    return 0;
}