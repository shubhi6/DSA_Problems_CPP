//Through this code we can find the element using iterative method which is more efficient than recursive method.
// Input: arr[] = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170}, x = 110
// Output: 6
// Explanation: Element x is present at index 6. 

// Input: arr[] = {10, 20, 30, 40, 60, 110, 120, 130, 170}, x = 175
// Output: -1
// Explanation: Element x is not present in arr[].

#include<iostream>
using namespace std;

int bsearch(int arr[],int n, int x)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(high+low)/2;
		if(arr[mid]==x)
		return mid;
		else if(arr[mid]>x)
		high=mid-1;
		else
		low=mid+1;
	}
	return -1;
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
	cout<<"Enter the element to be searched = ";
	cin>>x;
    cout<<"Index of the element is = ";
	cout<<bsearch(arr,n,x);
}
