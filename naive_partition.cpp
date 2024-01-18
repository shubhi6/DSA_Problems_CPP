// Naive partition: In this partition helps to maintain the relative order of the elements but this partition takes O(n) extra space.
// Naive partition

// Algorithm:

// Naivepartition(arr[],l,r)
// 1. Make a Temporary array temp[r-l+1] length
// 2. Choose last element as a pivot element
// 3. Run two loops:
//     -> Store all the elements in the temp array that are less than pivot element
//     -> Store the pivot element 
//     -> Store all the elements in the temp array that are greater than pivot element.
// 4.Update all the elements of arr[] with the temp[] array    


// QuickSort(arr[], l,  r)
// If r > l
//      1. Find the partition point of the array  
//               m = Naivepartition(a,l,r) 
//      2. Call Quicksort for less than partition point   
//              Call Quicksort(arr, l, m-1)
//      3. Call Quicksort for greater than the partition point 
//              Call Quicksort(arr, m+1, r)

#include <iostream>
using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int partition(int arr[], int start, int high) {
    int pivot = arr[high];
    int index = start;

    for (int i = start; i < high; ++i) {
        if (arr[i] < pivot) {
            std::swap(arr[i], arr[index]);
            ++index;
        }
    }

    std::swap(arr[index], arr[high]);
    return index;
}

void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int point = partition(arr, start, end);

        quicksort(arr, start, point - 1);
        quicksort(arr, point + 1, end);
    }
}

int main() {
	
    int size ;
    cout<<"Enter size of array = ";
    cin>>size;
    cout<<"Enter elements of array = ";
    int numbers[size];
    for(int i=0;i<size;i++)
    cin>>numbers[i];

    // rearrange using naive partition
    quicksort(numbers, 0, size - 1);

    print(numbers, size);

    return 0;
}

