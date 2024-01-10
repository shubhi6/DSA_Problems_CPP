#include<iostream>
using namespace std;

int dlt(int arr[],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	if(arr[i]==x)
	break;
	if(i==n)
	return n;
	for(int j=i;j<n-1;j++)
	arr[j]==arr[j+1];
	return (n-1);
}

int main()
{
	int n,x,arr[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(int j=0;j<n;j++)
	{
		cin>>arr[j];
	}
	cout<<"Enter a key = ";
	cin>>x;
	cout<<dlt(arr,n,x);
	return 0;
	
	
}
