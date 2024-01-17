// C++ STL provides a built-in function sort() that sorts a vector or array (items with random access). 

// Syntax to sort an Array:
 
// sort(arr, arr+n);

// Here, arr is the name or base address of the array
// and, n is the size of the array.

// How to sort in descending order?
	
// The sort() function takes a third parameter that is used to specify the order in which elements are to be sorted.
// We can pass "greater<type> ()" function to sort in descending order. 
// This function does comparison in a way that puts greater element before.

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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

