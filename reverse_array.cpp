//Through this code we can reverse all the elements in the array.

#include<iostream>
using namespace std;

int reverse(int arr[], int n)
{
	int i,low=0,high=n-1,temp;
	while(low<high)
	{
		temp=arr[low];
	    arr[low]=arr[high];
	    arr[high]=temp;
	    high--;
    	low++;
	}
	
}

void printArray(int arr[], int n)
{
        for (int i = 0; i <n; i++)
        cout << arr[i] << " ";

}

int main()
{
	int j,n,arr[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of array = ";
	for(j=0;j<n;j++)
	cin>>arr[j];
	reverse(arr,n);
	
	cout << "Reversed array is = " ;
	
	// To print the Reversed array
	printArray(arr, n);
	 
}
