#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows : ";
    cin >> m;
    cout << "Enter number of columns : ";
    cin >> n;

    vector< vector<int> > arr;
    for (int i = 0; i < m; i++) {
        vector<int> v; // Initialize v for each row
        for (int j = 0; j < n; j++) {
            v.push_back(10); // Push 10 into v for each column
        }
        arr.push_back(v); // Push v into arr for each row
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

