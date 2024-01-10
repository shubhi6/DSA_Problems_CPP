#include<iostream>
using namespace std;

int search(int arr[],int n,int x)
{
	for(int i=0;i<n;i++)
	if(arr[i]==x)
	return i;
	return -1;
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
	cout<<search(arr,n,x);
	return 0;
	
	
}
