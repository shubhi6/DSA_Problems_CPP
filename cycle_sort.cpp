// Cycle sort is an in-place sorting Algorithm, unstable sorting algorithm, 
// and a comparison sort that is theoretically optimal in terms of the total number of writes to the original array. 
 

// It is optimal in terms of the number of memory writes. It minimizes the number of memory writes to sort 
// (Each value is either written zero times if it’s already in its correct position or written one time to its correct position.)
// It is based on the idea that the array to be sorted can be divided into cycles. Cycles can be visualized as a graph.
//  We have n nodes and an edge directed from node i to node j if the element at i-th index must be present at j-th index in the sorted array. 
//  EXAMPLE :
//  Cycle in arr[] = {2, 4, 5, 1, 3} 
//  Cycle in arr[] = {4, 3, 2, 1}

#include <iostream>
using namespace std;
 

void cycleSort (int arr[], int n)
{
   
    int writes = 0;
 
    for (int cycle_start=0; cycle_start<=n-2; cycle_start++)
    {
        
        int item = arr[cycle_start];
 
        
        int pos = cycle_start;
        for (int i = cycle_start+1; i<n; i++)
            if (arr[i] < item)
                pos++;
 
        
        if (pos == cycle_start)
            continue;
 
       
        while (item == arr[pos])
            pos += 1;
 
        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }
 
       
        while (pos != cycle_start)
        {
            pos = cycle_start;
 
           
            for (int i = cycle_start+1; i<n; i++)
                if (arr[i] < item)
                    pos += 1;
 
           
            while (item == arr[pos])
                pos += 1;
 
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
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
    cycleSort(arr,  n) ;
 
    cout << "After sort : ";
    for (int i =0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
