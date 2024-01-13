// Given a binary array, we need to convert this array into an array that either contains all 1s or all 0s. 
//We need to do it using the minimum number of group flips. 
// Examples : 

// Input : arr[] = {1, 1, 0, 0, 0, 1}
// Output :  From 2 to 4
// Explanation : We have two choices, we make all 0s or do all 1s. 
//We need to do two group flips to make all elements 0 and one group flip to make all elements 1.  
//Since making all elements 1 takes the least group flips, we do this.
 

// Input : arr[] = {1, 0, 0, 0, 1, 0, 0, 1, 0, 1}
// Output :  
// From 1 to 3
// From 5 to 6
// From 8 to 8
 

// Input : arr[] = {0, 0, 0}
// Output :  
// Explanation : Output is empty, we need not to make any change
 

// Input : arr[] = {1, 1, 1}
// Output :  
// Explanation : Output is empty, we need not to make any change
 

// Input : arr[] = {0, 1}
// Output :   
// From 0 to 0  
// OR
// From 1 to 1
// Explanation :  Here number of flips are same either we make all elements as 1 or all elements as 0.
 

#include<iostream>
using namespace std;

void minimum_consecutive_flips(bool arr[],int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
		{
			if(arr[i]!=arr[0])
			cout<<"From"<<" "<<i<<" "<<"To"<<" ";
			else
			cout<<(i-1)<<endl;
		}
		
	}
	
		if(arr[n-1]!=arr[0])
		cout<<(n-1)<<endl;
}



int main()
{
	int j,n;
	cout<<"Enter size of array = ";
	cin>>n;
	bool arr[n];
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	minimum_consecutive_flips(arr,n);
}
