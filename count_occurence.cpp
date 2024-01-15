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


int lastocc(int arr[], int n, int x)
{
    int low = 0, high = n - 1, res = -1;
	while (low <= high) {

		// Normal Binary Search Logic
		int mid = (low + high) / 2;

		if (arr[mid] > x)
			high = mid - 1;
		else if (arr[mid] < x)
			low = mid + 1;

		// If arr[mid] is same as x, we
		// update res and move to the right
		// half.
		else {
			res = mid;
			low = mid + 1;
		}
	}
	return res;
}


int countocc(int arr[],int n, int x)
{
	int first=firstocc(arr,n,x);
	if(first==-1)
	return 0;
	else
	return (lastocc(arr,n,x)-first+1);
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
    cout<<"Number of times element occured is = ";
	cout<<countocc(arr,n,x);
}
