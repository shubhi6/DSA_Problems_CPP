#include<iostream>
using namespace std;

int getlargest(int arr[], int n)
{
	int i,res=0;
	for(i=1;i<n;i++)
	{
		if(arr[i]>arr[res])
		res=i;
	}
	cout<<"Largest Element is = "<< arr[res] <<endl<<"Index of largest element is = ";
	return res;
	
}

int main()
{
	int j,n,arr[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<getlargest(arr,n);
}
