 #include<iostream>
 #include<algorithm>
using namespace std;

int main()
{
	int j,n,x;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	int arr[n];
	for(j=0;j<n;j++)
	cin>>arr[j];
    sort(arr, arr+n, greater<int>());
    cout << "Array after sorting : \n";
    for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
    
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

