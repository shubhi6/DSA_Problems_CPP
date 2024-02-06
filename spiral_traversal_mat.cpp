#include <iostream>
using namespace std;

const int MAX = 100;

void spiralTraversal(int mat[MAX][MAX], int m, int n) {
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    
    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; ++i)
            cout << mat[top][i] << " ";
        top++;
        
        // Print rightmost column
        for (int i = top; i <= bottom; ++i)
            cout << mat[i][right] << " ";
        right--;
        
        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i)
                cout << mat[bottom][i] << " ";
            bottom--;
        }
        
        // Print leftmost column
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                cout << mat[i][left] << " ";
            left++;
        }
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns : " << endl;
    cin >> m >> n;

    int mat[MAX][MAX];

    cout << "Enter matrix elements : " << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << "Spiral traversal of matrix : " << endl;
    spiralTraversal(mat, m, n);

    return 0;
}

