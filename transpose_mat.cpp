#include <iostream>
using namespace std;

const int MAX = 100;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void transposeMatrix(int mat[MAX][MAX], int m, int n) {
    // Performing the transpose using swap function
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Swap mat[i][j] with mat[j][i]
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Displaying the transposed matrix
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    int mat[MAX][MAX];

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    transposeMatrix(mat, m, n);

    return 0;
}

