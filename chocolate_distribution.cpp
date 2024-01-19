// Chocolate Distribution Problem

// Given an array of N integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

// Each student gets one packet.
// The difference between the number of chocolates in the packet with maximum chocolates and the packet with minimum chocolates given to the students is minimum.
// Examples:

 

// Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
// Output: Chocolate distribution = 2 
// Explanation:
// We have seven packets of chocolates and we need to pick three packets for 3 students 
// If we pick 2, 3 and 4, we get the minimum difference between maximum and minimum packet sizes.

// Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m = 5 
// Output: Chocolate distribution =  6 

#include <algorithm>
#include <iostream>
using namespace std;

int chocodist(int arr[], int n, int x)
{
    if(x>n)
    return -1;
    sort(arr, arr + n);
    int res=arr[x-1]-arr[0];
    for(int i=1;(i+x-1)<n;i++)
    res=min(res,arr[i+x-1]-arr[i]);
    return res;
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
	cout<<"Enter the number of distributions  = ";
	cin>>x;
    cout << "Chocolate distribution = " << chocodist(arr, n, x);
    return 0;
}
