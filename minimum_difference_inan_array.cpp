#include <bits/stdc++.h>
using namespace std;

int mindiff(int arr[], int n)
{
    sort(arr, arr + n);
    int res=INT_MAX;
    for(int i=1;i<n;i++)
    res=min(res,arr[i]-arr[i-1]);
    return res;
    
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
    cout << "Minimum difference in an array = " << mindiff(arr, n);
    return 0;
}
