// Through this code we are given a sorted array that is rotated a certain number of times . 
// Our task is to detect the presence of a given target element in the array
// EXAMPLE:
// Input- arr[]={10,20,30,40,50,8,9} x=30
// Output- 2 // index of the element.

// Input- arr[]={100,200,300,10,20} x=40
// Output- -1 // this shows element is not present.

#include<iostream>
using namespace std;

int search(int arr[],int n, int x)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(high+low)/2;
		if(arr[mid]==x)
		return mid;
		 if(arr[low]<=arr[mid])
		 {
		 	if(x<arr[mid] && x>=arr[low])
		   	high=mid-1;
		    else
		    low=mid+1;
		 }
		 else
		 {
		 	if(x>arr[mid] && x<=arr[high])
		   	low=mid+1;
		    else
		    high=mid-1;
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
    cout<<"Index of the element is = ";
	cout<<search(arr,n,x);
}
