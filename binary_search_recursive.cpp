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
