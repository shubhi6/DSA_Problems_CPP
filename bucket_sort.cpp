// Bucket sort is mainly useful when input is uniformly distributed over a range. For example, consider the following problem. 
// // Sort a large set of floating point numbers which are in range from 0.0 to 1.0 and are uniformly distributed across the range. 
// How do we sort the numbers efficiently?
// A simple way is to apply a comparison based sorting algorithm.
// The lower bound for Comparison based sorting algorithm (Merge Sort, Heap Sort, Quick-Sort .. etc) is Ω(n Log n), i.e., they cannot do better than nLogn. 
// Can we sort the array in linear time? Counting sort can not be applied here as we use keys as index in counting sort. Here keys are floating point numbers.  
// The idea is to use bucket sort. Following is bucket algorithm.

// bucketSort(arr[], n)
// 1) Create n empty buckets (Or lists).
// 2) Do following for every array element arr[i].
// .......a) Insert arr[i] into bucket[n*array[i]]
// 3) Sort individual buckets using insertion sort.
// 4) Concatenate all sorted buckets.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n)
{
    vector<float> b[n];

   
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

  
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main()
{
    int n;
    cout << "Enter size of array = ";
    cin >> n;
    cout << "Enter elements of array = ";
    float arr[n];
    for (int j = 0; j < n; j++)
        cin >> arr[j];

    bucketSort(arr, n);

    cout << "Sorted array is = ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

