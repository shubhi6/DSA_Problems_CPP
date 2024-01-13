#include<iostream>
using namespace std;

bool epoint(int arr[], int n)
{
	int i,res=0;
	for(i=0;i<n;i++)
	res+=arr[i];
	int ls=0;
	for(i=0;i<n;i++)
	{
		res-=arr[i];
		if(ls=res)
			return true;// 1 means true
			ls+=arr[i];
	       return false;// 0 means false
		
	}
	
	
}

int main()
{
	int j,n,arr[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<epoint(arr,n);
}
