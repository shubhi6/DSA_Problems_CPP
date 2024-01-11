//Through this code we can get the second largest number or element of the array.

#include<iostream>
using namespace std;
//To get the largest number or element of the array.
int getlargest(int arr[], int n)
{
	int i,res=0;
	for(i=1;i<n;i++)
	{
		if(arr[i]>arr[res])
		res=i;
	}
	return res;
	
}
//To get the second largest number or element of the array.
int secondlargest(int arr[],int n)
{
	int largest=getlargest(arr,n);
	int i, res=-1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=arr[largest])
		{
			if(res==-1)
			res=i;
			else if(arr[i]>arr[res])
			res=i;
		}
	}
	cout<<"Second largest Element is = "<< arr[res] <<endl<<"Index of second largest element is = ";
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
	cout<<secondlargest(arr,n);
}
