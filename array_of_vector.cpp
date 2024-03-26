//.........ARRAY'S OF VECTOR........

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int m,n;
	cout<<"Enter number of rows : ";
	cin>>m;
	cout<<"Enter number of columns : ";
	cin>>n;
	
	vector<int> arr[m];
	
	for(int i=0;i<m;i++)
	 for(int j=0;j<n;j++)
	 arr[i].push_back(10);
	 
	 for(int i=0;i<m;i++)
	  for(int j=0;j<n;j++)
	  cout<<arr[i][j]<<" ";
	  
	return 0;  
	
}
