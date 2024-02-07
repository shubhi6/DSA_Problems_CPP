

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

