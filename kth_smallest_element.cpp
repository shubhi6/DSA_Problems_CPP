#include <algorithm>
#include <iostream>
using namespace std;

int kthSmallest(int arr[], int n, int x)
{
    // Sort the given array
    sort(arr, arr + n);
    return arr[x - 1];
}

int main()
{
    int j,n,x;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	int arr[n];
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<"Enter the value of K = ";
	cin>>x;
    cout << "K'th smallest element is " << kthSmallest(arr, n, x);
    return 0;
}
