#include <iostream>
using namespace std;

const int MAX = 100;

void boundaryTraversal(int mat[MAX][MAX], int m, int n) {
    if (m == 1) {
        // Only one row, so print the entire row
        for (int i = 0; i < n; i++)
            cout << mat[0][i] << " ";
    } else if (n == 1) {
        // Only one column, so print the entire column
        for (int i = 0; i < m; i++)
            cout << mat[i][0] << " ";
    } else {
        // Traverse the boundary elements
        for (int i = 0; i < n; i++)
            cout << mat[0][i] << " ";

        for (int i = 1; i < m; i++)
            cout << mat[i][n - 1] << " ";

        for (int i = n - 2; i >= 0; i--)
            cout << mat[m - 1][i] << " ";

        for (int i = m - 2; i >= 1; i--)
            cout << mat[i][0] << " ";
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns : "<< endl;
    cin >> m >> n;

    int mat[MAX][MAX];

    cout << "Enter matrix elements :" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Boundary elements of the matrix are : "<<endl;
    boundaryTraversal(mat, m, n);

    return 0;
}

