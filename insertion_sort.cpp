#include<iostream>
using namespace std;

int insertionsort(int arr[],int n)
{
	 int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

void printArray(int arr[], int n) 
{ 
    int i; 
    cout << "Sorted array = ";
    for (i = 0; i < n; i++) 
    cout << arr[i] << " "; 
    cout << endl;
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
    insertionsort(arr,n);
    printArray(arr, n);
}
