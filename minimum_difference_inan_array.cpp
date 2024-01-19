// Find minimum difference between any two elements (pair) in given array

// Given an unsorted array, find the minimum difference between any pair in the given array.

// Examples :

// Input: {1, 5, 3, 19, 18, 25}
// Output: Minimum difference in an array = 1
// Explanation: Minimum difference is between 18 and 19

// Input: {30, 5, 20, 9}
// Output:Minimum difference in an array =  4
// Explanation: Minimum difference is between 5 and 9

// Input: {1, 19, -4, 31, 38, 25, 100}
// Output: Minimum difference in an array = 5
// Explanation: Minimum difference is between 1 and -4

#include <bits/stdc++.h>
using namespace std;

int mindiff(int arr[], int n)
{
    sort(arr, arr + n);
    int res=INT_MAX;
    for(int i=1;i<n;i++)
    res=min(res,arr[i]-arr[i-1]);
    return res;
    
}

int main()
{
    int j,n;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	int arr[n];
	for(j=0;j<n;j++)
	cin>>arr[j];
    cout << "Minimum difference in an array = " << mindiff(arr, n);
    return 0;
}
