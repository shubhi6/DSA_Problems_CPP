// Taking an array of N non-negative integers arr[] representing an elevation map where the width of each bar is 1, 
// compute how much water it is able to trap after raining.

// Examples:  

// Input: arr[] = {2, 0, 2}
// Output: 2
// Explanation: The structure is like below.
// We can trap 2 units of water in the middle gap.



// Input: arr[]   = {3, 0, 2, 0, 4}
// Output: 7
// Explanation: Structure is like below.
// We can trap “3 units” of water between 3 and 2,
// “1 unit” on top of bar 2 and “3 units” between 2 and 4.



// Input: arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
// Output: 6
// Explanation: The structure is like below.
// Trap “1 unit” between first 1 and 2, “4 units” between
// first 2 and 3 and “1 unit” between second last 1 and last 2

	
#include<iostream>
#include<cmath>
using namespace std;

int getwater(int arr[],int n)
{
	int res=0,i;
	int lmax[n],rmax[n];
	
	lmax[0]=arr[0];
	for(i=1;i<n;i++)
	lmax[i]=max(arr[i],lmax[i-1]);
	
	
	rmax[n-1]=arr[n-1];
	for(i=n-2;i>=0;i--)
	rmax[i]=max(arr[i],rmax[i+1]);
	
	
	for(i=1;i<n-1;i++)
	res=res+(min(lmax[i],rmax[i]))-arr[i];
	
	return res;
	
}

int main()
{
	int j,n,arr[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Maximum units of water that can be trapped = ";
	cout<<getwater(arr,n);
}
