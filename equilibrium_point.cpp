// The equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes. 
// Through this code we can find the whether the array has equilibrium point or not.
// Examples: 

// Input: A[] = {-7, 1, 5, 2, -4, 3, 0} 
// Output: 3 //index of 2
// 3 is an equilibrium index, because: 
// A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

 

// Input: A[] = {1, 2, 3} 
// Output: -1 

 

#include<iostream>
using namespace std;

bool epoint(int arr[], int n)
{
	int i,res=0;
	for(i=0;i<n;i++)
	res+=arr[i];
	int ls=0;
	for(i=0;i<n;i++)
	{
		res-=arr[i];
		if(ls=res)
			return true;// 1 means true
			ls+=arr[i];
	       return false;// 0 means false
		
	}
	
	
}

int main()
{
	int j,n,arr[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<epoint(arr,n);
}
