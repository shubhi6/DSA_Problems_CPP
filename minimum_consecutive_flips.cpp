#include<iostream>
using namespace std;

void minimum_consecutive_flips(bool arr[],int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
		{
			if(arr[i]!=arr[0])
			cout<<"From"<<" "<<i<<" "<<"To"<<" ";
			else
			cout<<(i-1)<<endl;
		}
		
	}
	
		if(arr[n-1]!=arr[0])
		cout<<(n-1)<<endl;
}



int main()
{
	int j,n;
	cout<<"Enter size of array = ";
	cin>>n;
	bool arr[n];
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	minimum_consecutive_flips(arr,n);
}
