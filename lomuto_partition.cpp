// Lomuto partition: In this partition, The last element chooses as a pivot in this partition. 
//  The pivot acquires its required position after partition but more comparison takes place in this partition.
// Lomuto partition 

// Lomuto’s Partition Algorithm (unstable algorithm)
// Lomutopartition(arr[], lo, hi) 

//     pivot = arr[hi]
//     i = lo     // place for swapping
//     for j := lo to hi – 1 do
//         if arr[j] <= pivot then
//             swap arr[i] with arr[j]
//             i = i + 1
//     swap arr[i] with arr[hi]
//     return i

    
// QuickSort(arr[], l,  r)

// If r > l
//      1. Find the partition point of the array  
//               m =Lomutopartition(a,l,r) 
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

int sort(int numbers[], int start, int last) {
    int pivot = numbers[last];
    int index = start - 1;
    int temp = 0;

    for (int i = start; i < last; ++i) {
        if (numbers[i] < pivot) {
            ++index;

            // swap the position
            temp = numbers[index];
            numbers[index] = numbers[i];
            numbers[i] = temp;
        }
    }

    int pivotposition = ++index;

    temp = numbers[index];
    numbers[index] = pivot;
    numbers[last] = temp;

    return pivotposition;
}

void quicksort(int numbers[], int start, int end) {
    if (start < end) {
        int pivot_position = sort(numbers, start, end);
        quicksort(numbers, start, pivot_position - 1);
        quicksort(numbers, pivot_position + 1, end);
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
    // rearrange using lomuto partition
    quicksort(numbers, 0, size - 1);

    print(numbers, size);

    return 0;
}

