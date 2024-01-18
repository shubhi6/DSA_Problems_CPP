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

