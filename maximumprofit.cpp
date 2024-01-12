#include<iostream>
#include<cmath>
using namespace std;

int maxprofit(int price[], int n)
{

	int i=1,profit=0;
	for(i=1;i<n;i++)
	{
		if(price[i]>price[i-1])
		profit+=(price[i]-price[i-1]);
	}
	return profit;
	
}   


int main()
{
	int j,n,arr[n],d;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
    cout<<"Maximum profit is = "<<maxprofit(arr,n);
 
}
