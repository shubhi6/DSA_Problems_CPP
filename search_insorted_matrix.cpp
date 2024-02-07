//Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it.
// Otherwise, print "Not Found". In the given matrix, every row and column is sorted in increasing order. 
// The designed algorithm should have linear time complexity. 
//
//Example: 
// 
//Input: mat[4][4] = { {10, 20, 30, 40},
//                     {15, 25, 35, 45},
//                     {27, 29, 37, 48},
//                     {32, 33, 39, 50}}
//           x = 29
//Output: Found at (2, 1)
//Explanation: Element at (2,1) is 29
//
//
//Input : mat[4][4] = { {10, 20, 30, 40},
//                      {15, 25, 35, 45},
//                      {27, 29, 37, 48},
//                      {32, 33, 39, 50}};
//          x = 100
//Output : Element not found
//Explanation: Element 100 is not found

#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int> >& mat, int x) {
    int n = mat.size();
    if (n == 0)
        return false;

    int smallest = mat[0][0], largest = mat[n - 1][n - 1];
    if (x < smallest || x > largest)
        return false;

    // set indexes for top right element
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (mat[i][j] == x) {
            cout << "Element found at " << i << ", " << j;
            return true;
        }
        if (mat[i][j] > x)
            j--;
        else
            i++;
    }

    cout << "Element not found";
    return false;
}

// Driver code
int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    vector<vector<int> > mat(n, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    search(mat, target);

    return 0;
}

