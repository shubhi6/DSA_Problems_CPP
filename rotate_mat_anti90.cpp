// Given a Square Matrix of dimension N * N. The task is to rotate the matrix in anti-clock wise direction by 90 degrees.



// On observing carefully, we can easily conclude that:
// first row of destination ------> last column of source
// second row of destination ------> second last column of source
// .
// .
// .
// .
// last row of destination ------> first column of source



// Below steps demonstrate the idea:
// First Cycle (Involves Red Elements)
//  1  2  3 4 
//  5  6  7  8 
//  9 10 11 12 
//  13 14 15 16 

 
// Moving first group of four elements (First
// elements of 1st row, last row, 1st column 
// and last column) of first cycle in counter
// clockwise. 
//  4  2  3 16
//  5  6  7 8 
//  9 10 11 12 
//  1 14  15 13 
 
// Moving next group of four elements of 
// first cycle in counter clockwise 
//  4  8  3 16 
//  5  6  7  15  
//  2  10 11 12 
//  1  14  9 13 

// Moving final group of four elements of 
// first cycle in counter clockwise 
//  4  8 12 16 
//  3  6  7 15 
//  2 10 11 14 
//  1  5  9 13 


// Second Cycle (Involves Blue Elements)
//  4  8 12 16 
//  3  6 7  15 
//  2  10 11 14 
//  1  5  9 13 

// Fixing second cycle
//  4  8 12 16 
//  3  7 11 15 
//  2  6 10 14 
//  1  5  9 13


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

