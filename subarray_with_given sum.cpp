#include<iostream>
using namespace std;

int issubarr(int arr[],int sum, int n)
{
	int i,s=0,curr=0;
	for(i=0;i<n;i++)
	{
		curr+=arr[i];
		while(sum<curr)
		{
			curr-=arr[s];
			s++;
		}
		if(curr==sum)
		return true;// 1 means true
	}
	return false;// 0 means false
	
}

int main()
{
	int j,n,arr[n],sum;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Enter the sum = ";
	cin>>sum;
	cout<<issubarr(arr,sum,n);
}
