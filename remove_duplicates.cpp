#include<iostream>
using namespace std;

int removedups(int arr[], int n)
{
	int i,res=1;
	for(i=1;i<n;i++)
	{
		if(arr[i]!=arr[res-1])
		{
			arr[res]=arr[i];
		    res++;
		}
	}
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
   cout<<"Before Removal"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }

       cout<<endl;

       n = removedups(arr, n);

       cout<<"After Removal"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
    
}
