// Find the union of two unsorted arrays using hash
// Example:

// A[]: 2 6 9 4 1
// B[]: 36 8 1 6 9
// Size of the union: 7

// A[]:  9 8 2 6 7 4
// B[]: 2 6 7
// Size of the union: 6  

#include <iostream>
#include <unordered_set>

using namespace std;

int findUnion(int a[], int b[], int m, int n) {
    unordered_set<int> s(a, a + m);

    for (int i = 0; i < n; i++)
        s.insert(b[i]);

    return s.size();
}

int main() {
    int m, n;

    cout << "Enter the size of the first array: ";
    cin >> m;
    cout << "Enter the elements of the first array: ";
    int *a = new int[m];

    for (int i = 0; i < m; i++)
        cin >> a[i];

    cout << "Enter the size of the second array: ";
    cin >> n;
    cout << "Enter the elements of the second array: ";
    int *b = new int[n];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    int unionSize = findUnion(a, b, m, n);
    cout << "Size of the union: " << unionSize << endl;

    return 0;
}
