#include<iostream>
#include<cmath>
using namespace std;

int longestevenodd(int arr[],int n)
{
	int res=1,i,curr=1;
    for(int i=1;i<n;i++)
    {
    	if((arr[i]%2==0 && arr[i-1]%2!=0)||(arr[i-1]%2==0 && arr[i]%2!=0))
    	{
    		curr++;
    		res=max(res,curr);
		}
		else
		curr=1;
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
	cout<<"Longest subarray of even odd = ";
	cout<<longestevenodd(arr,n);
}
