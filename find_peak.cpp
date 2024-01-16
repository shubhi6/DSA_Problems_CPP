//Through this code we can find a peak element in the array. A peak element is an element whose neighbors have value smaller than that of the element. 

// Note: For corner elements, we need to consider only one neighbor. 

// Example:

// Input: array[]= {5, 10, 20, 15}
// Output: 20
// Explanation: The element 20 has neighbors 10 and 15, both of them are less than 20.

// Input: array[] = {10, 20, 15, 2, 23, 90, 67}
// Output: 20 or 90
// Explanation: The element 20 has neighbors 10 and 15, both of them are less than 20, similarly 90 has neighbors 23 and 67.

#include<iostream>
using namespace std;

int findPeak(int arr[],int n)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(high+low)/2;
		if((mid==0||arr[mid-1]<=arr[mid]) && (mid==n-1||arr[mid-1]<=arr[mid]))
		return arr[mid];
		else if(mid>0 && arr[mid-1]>=arr[mid])
		high=mid-1;
		else
		low=mid+1;
	}
	return -1;
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
    cout<<"Peak element is = ";
	cout<<findPeak(arr,n);
}
