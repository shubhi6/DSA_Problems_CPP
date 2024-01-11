#include<iostream>
using namespace std;

int leftrotate(int arr[], int n)
{
	int i;
	int temp=arr[0];
	for(i=1;i<n;i++)
	
		arr[i-1]=arr[i];
		arr[n-1]=temp;
	
	
}

int main()
{
	int i,n,arr[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(i=0;i<n;i++)
	cin>>arr[i];
	  cout<<"Before Rotation"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }

       cout<<endl;

       leftrotate(arr,n);
       cout<<"After Rotation"<<endl;

       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }

}
