//..............Sort K-Sorted Array...........

#include <bits/stdc++.h>
using namespace std;

void sortK(int arr[], int n, int k)
{
    int size;
    size=(n==k)?k:k+1;
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr +size);

    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while (pq.empty() == false) {
        arr[index++] = pq.top();
        pq.pop();
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int k = 3;
    int arr[] = { 2, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortK(arr, n, k);

    cout << "Following is sorted array" << endl;
    printArray(arr, n);

    return 0;
}


// Output
// Following is sorted array
// 2 3 6 8 12 56 
// Time Complexity: O(k) + O((m) * log(k)) ,  where m = n - k
// Auxiliary Space: O(k)
