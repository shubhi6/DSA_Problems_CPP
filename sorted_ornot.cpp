//Through this code we can find whether the array is sorted or not.

#include <iostream>
#include <cmath>
using namespace std;

bool issorted(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[i])
				return false;
		}
	}

	return true;
} 


int main()
{
	int j,n,arr[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	if (issorted(arr,n))
		cout << "Array is sorted\n";
	else
		cout << "Array is not sorted\n";
}
