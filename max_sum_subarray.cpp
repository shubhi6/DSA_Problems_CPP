//Through this code we can  find the elements of a contiguous subarray of numbers that has the largest sum.

//Examples:

//Input: arr = [-2, -3, 4, -1, -2, 1, 5, -3]
//Output: [4, -1, -2, 1, 5]
//Explanation: 
//In the above input the maximum contiguous subarray sum is 7 and the elements of the subarray are [4, -1, -2, 1, 5]

//Input: arr = [-2, -5, 6, -2, -3, 1, 5, -6] 
//Output: [6, -2, -3, 1, 5] 
//Explanation: 
//In the above input the maximum contiguous subarray sum is 7 and the elements of the subarray are [6, -2, -3, 1, 5]

#include<iostream>
#include<cmath>
using namespace std;

int maxsubsum(int arr[],int n)
{
	int res=arr[0],i,maxend=arr[0];
    for(int i=1;i<n;i++)
    {
    	maxend = max((maxend+arr[i]),arr[i]);
    	res = max(res,maxend);
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
	cout<<"Maximum sum of subarray = ";
	cout<<maxsubsum(arr,n);
}
