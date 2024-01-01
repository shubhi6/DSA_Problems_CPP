//insertion code for random insertion in fixed size array

#include<iostream>
using namespace std;

int insert(int n, int arr[], int x, int pos) {
    if (pos < 0 || pos > n) {
        cout << "Invalid position for insertion." << endl;
        return n; // Return the original size of the array
    }

    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = x;
    return (n + 1);
}

int main() {
    int arr[10] = {3,8,5,6,7};
    int n = 5;

    cout << "\n Before insertion: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " " << endl;

    cout << "element to be inserted = ";
    int x;
    cin >> x;

    int pos;
    cout << "enter the position to insert element= ";
    cin >> pos;

    n = insert(n, arr, x, pos);

    cout << "\n After Insertion: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " " << endl;

    return 0;
}

