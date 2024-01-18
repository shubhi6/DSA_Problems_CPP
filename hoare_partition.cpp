// Hoare's partition: In this partition, The first element chooses as a pivot in this partition. 
// The pivot displaces its required position after partition but less comparison takes place as compared to the Lomuto partition.
// Hoare's Partition 

// Hoare’s Partition Scheme works by initializing two indexes that start at two ends, 
//     the two indexes move toward each other until an inversion is (A smaller value on the left side and a greater value on the right side) found. 
//     When an inversion is found, two values are swapped and the process is repeated.

// Algorithm: 

// Hoarepartition(arr[], lo, hi)

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


   
// QuickSort(arr[], l,  r)

// If r > l
//      1. Find the partition point of the array  
//               m =Hoarepartition(a,l,r) 
//      2. Call Quicksort for less than partition point   
//              Call Quicksort(arr, l, m)
//      3. Call Quicksort for greater than the partition point 
//              Call Quicksort(arr, m+1, r)


#include <iostream>
using namespace std;

// Function to partition the array using Hoare's scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {
        // Find leftmost element greater than or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Find rightmost element smaller than or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If two pointers meet, the partitioning is done
        if (i >= j)
            return j;

        // Swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// The main function that implements QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now in the right place
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << " " << arr[i];

    std::cout << std::endl;
}

// Driver Code
int main() {
   int n ;
    cout<<"Enter size of array = ";
    cin>>n;
    cout<<"Enter elements of array = ";
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    // Sorting the array using QuickSort
    quickSort(arr, 0, n - 1);

    // Printing the sorted array
    printArray(arr, n);

    return 0;
}

