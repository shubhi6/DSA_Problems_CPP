#include<iostream>
using namespace std;

bool isfeasible(int arr[],int n,int k,int ans)
{
	int req=1,sum=0;
	for(int i=0;i<n;i++)
	{
		if(sum+arr[i]>ans)
		{
			req++;
			sum=arr[i];
		}
	    else
		sum+=arr[i];	
    }
    return(req<=k);
}

int minPages(int arr[],int n, int k)
{
	int sum=0,mx=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		mx=max(mx,arr[i]);
    }
    int low=mx,high=sum,res=0;
    while(low<=high)
    {
		int mid=(high+low)/2;
		if(isfeasible(arr,n,k,mid))
	    {
	    	res=mid;
	    	high=mid-1;
		}
		else
		low=mid+1;
	}
	return res;
}

int main()
{
	int j,n,k;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	int arr[n];
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Enter the number of students = ";
	cin>>k;
   cout<<"Minimum number of pages = ";
	cout<<minPages(arr,n,k);
}
