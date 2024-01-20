// Heap sort is a comparison based sorting technique based on Binary Heap data structure.
// It is similar to selection sort where we first find the maximum element and place the maximum element at the end. 
// We repeat the same process for remaining elements.
// Input data: [4, 10, 3, 5, 1]
//          4(0)
//         /   \
//      10(1)   3(2)
//     /   \
//  5(3)    1(4)

// The numbers in bracket represent the indices in the array 
// representation of data.

// Applying heapify procedure to index 1:
//          4(0)
//         /   \
//     10(1)    3(2)
//     /   \
// 5(3)    1(4)

// Applying heapify procedure to index 0:
//         10(0)
//         /  \
//      5(1)  3(2)
//     /   \
//  4(3)    1(4)

// The heapify procedure calls itself recursively to build heap
// in top down manner.


#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 

  
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

   
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);

       
        heapify(arr, i, 0);
    }
}

int main()
{
    int j, n;
    cout << "Enter size of array = ";
    cin >> n;
    cout << "Enter elements of array = ";
    int arr[n]; 
    for (j = 0; j < n; j++)
        cin >> arr[j];
    
    heapSort(arr,  n) ; 

    cout << "After sort : ";
    for (int i =0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}

