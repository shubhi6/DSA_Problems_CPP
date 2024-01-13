// Given an array arr[ ] of non-negative integers and an integer sum, find a subarray that adds to a given sum.

// Through this code can find whether the sum is equal to the sum of the integers given in an subarray or not. 
 
// Examples: 

// Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
// Output: Sum found between indexes 2 and 4
// Explanation: Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33

// Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
// Output: Sum found between indexes 1 and 4
// Explanation: Sum of elements between indices 1 and 4 is 4 + 0 + 0 + 3 = 7

// Input: arr[] = {1, 4}, sum = 0
// Output: No subarray found
// Explanation: There is no subarray with 0 sum

 

#include<iostream>
using namespace std;

int issubarr(int arr[],int sum, int n)
{
	int i,s=0,curr=0;
	for(i=0;i<n;i++)
	{
		curr+=arr[i];
		while(sum<curr)
		{
			curr-=arr[s];
			s++;
		}
		if(curr==sum)
		return true;// 1 means true
	}
	return false;// 0 means false
	
}

int main()
{
	int j,n,arr[n],sum;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Enter the sum = ";
	cin>>sum;
	cout<<issubarr(arr,sum,n);
}
