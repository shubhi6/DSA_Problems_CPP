//A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element). 

//Examples : 

//Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
//Output : Majority element is = 4
//         Majority element index of an array is = 4
//Explanation: The frequency of 4 is 5 which is greater than the half of the size of the array size. 

//Input : {3, 3, 4, 2, 4, 4, 2, 4}
//Output : No Majority Element
//Explanation: There is no element whose frequency is greater than the half of the size of the array size.


#include<iostream>
using namespace std;

int majority_element(int arr[],int n)
{
	int res=arr[0],count=1,i;
	for(i=1;i<n;i++)
	{
		if(arr[res]==arr[i])
		count++;
		else
		count--;
		if(count==0)
		{
			res=i;
			count=1;
		}
	}
	count=0;

	for(i=0;i<n;i++)
		if(arr[res]==arr[i])
		count++;
		if(count<=n/2)
		res=-1;
		cout<<"Majority element is = "<<arr[res]<<endl;
		cout<<"Majority element index of an array is = ";
	  return res;
	
	
}



int main()
{
	int j,n,arr[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	cout<<majority_element(arr,n);
}
