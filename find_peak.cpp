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
