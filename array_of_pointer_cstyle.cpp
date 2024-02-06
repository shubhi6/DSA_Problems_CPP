// C-style solution to write a general purpose matrix
// using array of pointer 

#include <iostream>
using namespace std;

void print(int *arr[], int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
}

int main() {
    int m, n;
    cout << "Enter number of rows : ";
    cin >> m;
    cout << "Enter number of columns : ";
    cin >> n;

    int **arr = new int *[m]; 

    for (int i = 0; i < m; i++)
        arr[i] = new int[n]; 
        
        
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = i; 
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

