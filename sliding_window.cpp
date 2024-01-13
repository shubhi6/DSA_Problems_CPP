//Through this code we can find the maximum sum of 'k' consecutive elements in the array.

// Input  : arr[] = {100, 200, 300, 400}
//          k = 2
// Output : 700

// Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
//          k = 4 
// Output : 39
// We get maximum sum by adding subarray {4, 2, 10, 23}
// of size 4.

// Input  : arr[] = {2, 3}
//          k = 3
// Output : Invalid
// There is no subarray of size 3 as size of whole
// array is 2.
 
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
