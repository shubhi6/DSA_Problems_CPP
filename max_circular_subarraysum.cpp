#include<iostream>
using namespace std;

int normal_maxsum(int arr[],int n)
{
	int res=arr[0],max_ending=arr[0];
	for(int i=1;i<n;i++)
	{
		max_ending=max(arr[i],(max_ending+arr[i]));
		res=max(res,max_ending);
	}
	return res;
}

int maxcircularsum(int arr[],int n)
{
	int max_normal=normal_maxsum(arr,n),i;
	
	if(max_normal<0)
	
	return max_normal;
	int arr_sum=0;
	for(i=0;i<n;i++)
	{
		arr_sum+=arr[i];
		arr[i]=-arr[i];
	}
	int max_circular= arr_sum + normal_maxsum(arr,n);
	
	return max(max_circular,max_normal);
	
}



int main()
{
	int j,n,arr[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Maximum sum of a circular subarray is = ";
	cout<<maxcircularsum(arr,n);
}
