//Let’s understand the Question more deeply. We are required to give the total number of inversions and the inversions are: For i & j < size of an array if i < j then you have to find pair (a[i], a[j]) such that a[i] > a[j].

//For example, for the given array: [5,3,2,1,4], (5, 3) will be a valid pair as 5 > 3 and
//index 0 < index 1. But (1, 4) cannot be valid pair.

#include <iostream>
using namespace std;

int main() {
    int n, ct = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                ct++;
            }
        }
    }
    cout << ct;
    return 0;
}

