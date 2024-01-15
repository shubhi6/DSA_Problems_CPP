#include<iostream>
using namespace std;

int count_1s_inbsearch(int arr[],int n)
{
int low = 0, high = n - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		if(arr[mid] == 0)
			low = mid + 1;
		else
		{
			if(mid == 0 || arr[mid - 1] == 0)
				return (n - mid);
			else 
				high = mid -1;
		}
	}

	return 0;		
}

int main()
{
	int j,n;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	int arr[n];
	for(j=0;j<n;j++)
	cin>>arr[j];
    cout<<"count of 1`s in an array is = ";
	cout<<count_1s_inbsearch(arr,n);
}
