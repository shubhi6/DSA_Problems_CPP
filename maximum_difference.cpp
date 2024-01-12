#include<iostream>
#include<cmath>
using namespace std;

int maxdiff(int arr[], int n)
{
	int res=arr[1]-arr[0];
	int i,minval=arr[0];
	for(i=1;i<n;i++)
	{
		res=max(res,arr[i]-minval);
		minval=min(minval,arr[i]);
	}
	return res;
}   




int main()
{
	int j,n,arr[n],d;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
  cout << "Maximum difference is " << maxdiff(arr, n);
 
}
