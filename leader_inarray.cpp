#include<iostream>
#include<cmath>
using namespace std;

void leader(int arr[], int n)
{

	int i;
	int curr=arr[n-1];
	cout<<curr<<" ";
	for(i=n-2;i>=0;i--)
	{
		if(curr<arr[i])
		{
			curr=arr[i];
			cout<<curr<<" ";
		}
	}
	
}   




int main()
{
	int j,n,arr[n],d;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
    leader(arr,n);
 
}
