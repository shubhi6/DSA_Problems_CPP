// Hoare’s Partition Scheme:

// Hoare’s Partition Scheme works by initializing two indexes that start at two ends, the two indexes move toward each other until an inversion is (A smaller value on the left side and greater value on the right side) found. When an inversion is found, two values are swapped and the process is repeated.

// Algorithm:

// partition(arr[], lo, hi)
//    pivot = arr[lo]
//    i = lo - 1  // Initialize left index
//    j = hi + 1  // Initialize right index

//    // Find a value in left side greater
//    // than pivot
//    do
//       i = i + 1
//    while arr[i] < pivot

//    // Find a value in right side smaller
//    // than pivot
//    do
//       j--;
//    while (arr[j] > pivot);

//    if i >= j then 
//       return j

//    swap arr[i] with arr[j]

#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (1) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
 
// Driver Code
int main()
{
    int j, n;
    cout << "Enter size of array = ";
    cin >> n;
    cout << "Enter elements of array = ";
    int arr[n];
    for (j = 0; j < n; j++)
    cin >> arr[j];
    quickSort(arr, 0, n - 1);
    cout<<"Sorted array: "<<"\n";
    printArray(arr, n);
    return 0;
}
