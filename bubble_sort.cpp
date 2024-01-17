 #include<iostream>
using namespace std;

int bubblesort(int arr[],int n)
{
	int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
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
    bubblesort(arr,n);
    printArray(arr, n);
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

