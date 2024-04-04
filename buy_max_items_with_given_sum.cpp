#include <bits/stdc++.h>
using namespace std;

int maxToys(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    int count = 0;
    while (pq.top() <= k) {
        count++;
        k = k - pq.top();
        pq.pop();
    }
    return count;
}

int main()
{
    int arr[] = { 1, 12, 5, 111, 200, 1000, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 50;

    cout << maxToys(arr, n, k);

    return 0;
}

