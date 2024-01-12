#include<iostream>
#include<cmath>
using namespace std;

int getwater(int arr[],int n)
{
	int res=0,i;
	int lmax[n],rmax[n];
	
	lmax[0]=arr[0];
	for(i=1;i<n;i++)
	lmax[i]=max(arr[i],lmax[i-1]);
	
	
	rmax[n-1]=arr[n-1];
	for(i=n-2;i>=0;i--)
	rmax[i]=max(arr[i],rmax[i+1]);
	
	
	for(i=1;i<n-1;i++)
	res=res+(min(lmax[i],rmax[i]))-arr[i];
	
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
	cout<<"Maximum units of water that can be trapped = ";
	cout<<getwater(arr,n);
}
