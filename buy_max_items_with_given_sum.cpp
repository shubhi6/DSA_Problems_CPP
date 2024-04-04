//...................Buy Maximum Items with Given Sum.....................

Given an array arr[] consisting of the cost of toys and an integer K depicting the amount of money available to purchase toys.
The task is to find the maximum number of toys one can buy with the amount K.
Note: One can buy only 1 quantity of a particular toy.

Examples: 

Input: arr[] = {1, 12, 5, 111, 200, 1000, 10, 9, 12, 15}, K = 50 
Output: 6 
Toys with amount 1, 5, 9, 10, 12, and 12 
can be purchased resulting in a total amount of 49. 
Hence, the maximum number of toys are 6.

Input: arr[] = {1, 12, 5, 111, 200, 1000, 10}, K = 50 
Output: 4

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

