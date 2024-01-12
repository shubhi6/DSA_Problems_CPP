//Through this code we can find the length of the longest Alternating Even Odd subarray present in the array. 

//Examples: 

//Input: a[] = {1, 2, 3, 4, 5, 7, 9} 
//Output: 5 
//Explanation: 
//The subarray {1, 2, 3, 4, 5} has alternating even and odd elements.

//Input: a[] = {1, 3, 5} 
//Output: 0 
//Explanation: 
//There is no such alternating sequence possible. 

#include<iostream>
#include<cmath>
using namespace std;

int longestevenodd(int arr[],int n)
{
	int res=1,i,curr=1;
    for(int i=1;i<n;i++)
    {
    	if((arr[i]%2==0 && arr[i-1]%2!=0)||(arr[i-1]%2==0 && arr[i]%2!=0))
    	{
    		curr++;
    		res=max(res,curr);
		}
		else
		curr=1;
	}
    
	return res;
	
}

int main()
{
	int j,n;
	cout<<"Enter size of array = ";
	cin>>n;
	int arr[n];
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Longest subarray of even odd = ";
	cout<<longestevenodd(arr,n);
}
