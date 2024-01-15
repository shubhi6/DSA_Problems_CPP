#include<iostream>
using namespace std;

int firstocc(int arr[],int n, int x)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(high+low)/2;
	    if(arr[mid]>x)
		high=mid-1;
		else if(arr[mid]<x)
		low=mid+1;
		else
		{
			if(mid==0||arr[mid]!=arr[mid-1])
			return mid;
			else
			return high=mid-1;
		}
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
    cout<<"Index of first occurence of element is = ";
	cout<<firstocc(arr,n,x);
}
