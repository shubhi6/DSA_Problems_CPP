//Write a program to print all the LEADERS in the array. 
//An element is a leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. 

//For example:

//Input: arr[] = {16, 17, 4, 3, 5, 2}, 
//Output: 17, 5, 2

//Input: arr[] = {1, 2, 3, 4, 5, 2}, 
//Output: 5, 2

#include<iostream>
#include<cmath>
using namespace std;

void leader(int arr[], int n)
{

	int i;
	int curr=arr[n-1];
	cout<<curr<<" ";
	for(i=n-2;i>=0;i--)
	{
		if(curr<arr[i])
		{
			curr=arr[i];
			cout<<curr<<" ";
		}
	}
	
}   




int main()
{
	int j,n,arr[n],d;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
    leader(arr,n);
 
}
