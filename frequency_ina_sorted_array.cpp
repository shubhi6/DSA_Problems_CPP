//Through this code we can find or optimize how many times a number or an elements in an array are repeated.
//ex if array is given as A[6]={ 10 20 20 30 30 30 }
//output will be   :  10    1
//                    20    2
//                    30    3

#include<iostream>
#include<cmath>
using namespace std;

void printfreq(int arr[], int n)
{

	int i=1,freq=1;
	while(i<n)
	{
		while(i<n && arr[i]==arr[i-1])
		{
			freq++;
			i++;
		}
		cout<<arr[i-1]<<" "<<freq<<endl;
		i++;
		freq=1;
	}
	if(n==1|| arr[n-1]!=arr[n-2])
	cout<<arr[n-1]<<" "<<1<<endl;
	
}   


int main()
{
	int j,n,arr[n],d;
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
    printfreq(arr,n);
 
}
