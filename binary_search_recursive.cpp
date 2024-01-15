//Through this code we can find the element using recursive method which is less efficient as compared to iterative method.
// Input: arr[] = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170}, x = 110
// Output: 6
// Explanation: Element x is present at index 6. 

// Input: arr[] = {10, 20, 30, 40, 60, 110, 120, 130, 170}, x = 175
// Output: -1
// Explanation: Element x is not present in arr[].


#include<iostream>
using namespace std;

int bsearch(int arr[],int low,int high, int x)
{
	if(low>high)
	return -1;
	int mid=(high+low)/2;
		if(arr[mid]==x)
		return mid;
		else if(arr[mid]>x)
		return bsearch(arr,low,mid-1,x);
		else
		return bsearch(arr,mid+1,high,x);
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
     int result = bsearch(arr, 0, n - 1, x);
	  (result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
}
