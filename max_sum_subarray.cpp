#include<iostream>
#include<cmath>
using namespace std;

int maxsubsum(int arr[],int n)
{
	int res=arr[0],i,maxend=arr[0];
    for(int i=1;i<n;i++)
    {
    	maxend = max((maxend+arr[i]),arr[i]);
    	res = max(res,maxend);
	}
    
	return res;
	
}

int main()
{
	int j,n;
	cout<<"Enter size of array = ";
	cin>>n;
	int arr[n];
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Maximum sum of subarray = ";
	cout<<maxsubsum(arr,n);
}
