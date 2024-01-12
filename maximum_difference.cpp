// Through this code we can find the maximum difference between the array elements.
//for example:

//Input : arr = {2, 3, 10, 6, 4, 8, 1}
//Output : 8
//Explanation : The maximum difference is between 10 and 2.

//Input : arr = {7, 9, 5, 6, 3, 2}
//Output : 2
//Explanation : The maximum difference is between 9 and 7.

#include<iostream>
#include<cmath>
using namespace std;

int maxdiff(int arr[], int n)
{
	int res=arr[1]-arr[0];
	int i,minval=arr[0];
	for(i=1;i<n;i++)
	{
		res=max(res,arr[i]-minval);
		minval=min(minval,arr[i]);
	}
	return res;
}   




int main()
{
	int j,n,arr[n],d;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
  cout << "Maximum difference is " << maxdiff(arr, n);
 
}
