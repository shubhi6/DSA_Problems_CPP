//anti-clockwise by 90

//#include <iostream>
//using namespace std;
//
//const int MAX = 100;
//
//void transpose(int mat[MAX][MAX], int n) {
//    for (int i = 0; i < n; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            swap(mat[i][j], mat[j][i]);
//        }
//    }
//}
//
//void reverseRows(int mat[MAX][MAX], int n) {
//    for (int i = 0; i < n; ++i) {
//        int start = 0;
//        int end = n - 1;
//        while (start < end) {
//            swap(mat[i][start], mat[i][end]);
//            start++;
//            end--;
//        }
//    }
//}
//
//void rotateAntiClockwise(int mat[MAX][MAX], int n) {
//    // Transpose the matrix
//    transpose(mat, n);
//
//    // Reverse each row
//    reverseRows(mat, n);
//}
//
//void displayMatrix(int mat[MAX][MAX], int n) {
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout << mat[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    int n;
//    cout << "Enter the size of the square matrix: ";
//    cin >> n;
//
//    int mat[MAX][MAX];
//
//    cout << "Enter matrix elements:" << endl;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cin >> mat[i][j];
//        }
//    }
//
//    cout << "Original Matrix:" << endl;
//    displayMatrix(mat, n);
//
//    rotateAntiClockwise(mat, n);
//
//    cout << "Matrix after rotating anticlockwise by 90 degrees:" << endl;
//    displayMatrix(mat, n);
//
//    return 0;
//}


// rotate clockwise by 90

#include <iostream>
using namespace std;

const int MAX = 100;

void transposeMatrix(int mat[MAX][MAX], int m, int n) {
    // Performing the transpose
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Swap mat[i][j] with mat[j][i]
            swap(mat[i][j], mat[j][i]);
        }
    }
}

void reverseRows(int mat[MAX][MAX], int m, int n) {
    // Reversing each row
    for (int i = 0; i < m; ++i) {
        int left = 0, right = n - 1;
        while (left < right) {
            swap(mat[i][left], mat[i][right]);
            ++left;
            --right;
        }
    }
}

void rotateMatrixClockwise(int mat[MAX][MAX], int m, int n) {
    transposeMatrix(mat, m, n);
    reverseRows(mat, m, n);
}

void displayMatrix(int mat[MAX][MAX], int m, int n) {
    cout << "Rotated Matrix:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
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

    rotateMatrixClockwise(mat, m, n);
    displayMatrix(mat, n, m); // The dimensions are swapped after rotation

    return 0;
}

