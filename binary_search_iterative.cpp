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
