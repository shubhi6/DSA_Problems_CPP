#include <bits/stdc++.h>
using namespace std;

void calculateSpan(int A[], int n, int ans[]) {
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
        int counter = 1;
        while ((i - counter) >= 0 && A[i] >= A[i - counter]) {
            counter += ans[i - counter];
        }
        ans[i] = counter;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int price[] = { 10, 4, 5, 90, 120, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    int S[n];
    calculateSpan(price, n, S);
    printArray(S, n);
    return 0;
}

