#include<iostream>
using namespace std;

int max_ksum(int arr[],int n,int k)
{
	 if (n < k) 
	 {
	 	cout << "Invalid";
        return -1;
	 }
	 
	int curr=0,i;
	for(i=0;i<k;i++)
		curr+=arr[i];
		int res=curr;
		
	for(i=k;i<n;i++)
	{
		curr=curr+arr[i]-arr[i-k];
		res=max(curr,res);
	}
	  return res;
	
}



int main()
{
	int j,n,k;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter the value of k = ";
	cin>>k;
	int *arr = new int[n];
    cout << "Enter elements of array = ";
    for (int j = 0; j < n; j++)
    cin >> arr[j];
	cout<<"Maximum sum of an k subarray is = ";
	cout<<max_ksum(arr,n,k);
}
