// Given an array and a number k where k is smaller than the size of the array, we need to find the k'th smallest element in the given array. It is given that all array elements are distinct.

// Examples:  

// Input: arr[] = {7, 10, 4, 3, 20, 15}, k = 3 
// Output: K'th smallest element is  = 7 

// Input: arr[] = {7, 10, 4, 3, 20, 15}, k = 4 
// Output: K'th smallest element is = 10 

#include <algorithm>
#include <iostream>
using namespace std;

int kthSmallest(int arr[], int n, int x)
{
    // Sort the given array
    sort(arr, arr + n);
    return arr[x - 1];
}

int main()
{
    int j,n,x;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	int arr[n];
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Enter the value of K = ";
	cin>>x;
    cout << "K'th smallest element is " << kthSmallest(arr, n, x);
    return 0;
}
