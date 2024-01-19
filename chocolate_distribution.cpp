#include <algorithm>
#include <iostream>
using namespace std;

int chocodist(int arr[], int n, int x)
{
    if(x>n)
    return -1;
    sort(arr, arr + n);
    int res=arr[x-1]-arr[0];
    for(int i=1;(i+x-1)<n;i++)
    res=min(res,arr[i+x-1]-arr[i]);
    return res;
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
	cout<<"Enter the number of distributions  = ";
	cin>>x;
    cout << "Chocolate distribution = " << chocodist(arr, n, x);
    return 0;
}
