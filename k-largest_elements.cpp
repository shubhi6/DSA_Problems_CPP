//........................K Largest Elements...............

// Method 1(Use Sorting) 
// 1) Sort the elements in descending order in O(n*log(n)) 
// 2) Print the first k numbers of the sorted array O(k). 
// Time complexity: O(n*log(n))
// Auxiliary Space: O(1)
    
#include <bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k)
{
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = { 1, 23, 12, 9, 30, 2, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    kLargest(arr, n, k);
}


// Output
// 50 30 23 


Method 2 (Use Max Heap) 
1) Build a Max Heap tree in O(n) 
2) Use Extract Max k times to get k maximum elements from the Max Heap O(k*log(n))

Time complexity: O(n + k*log(n)) 

Method 3 (Use Min Heap) 
Using Min Heap.
Time Complexity: O(nlogn)
Auxiliary Space: O(n)
 
#include <bits/stdc++.h>
using namespace std;

void firstKElements(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for (int i = 0; i < k; i++)
    {
        minHeap.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (minHeap.top() > arr[i])
            continue;
        else
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    while (minHeap.empty() == false)
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}

int main()
{
    int arr[] = {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    firstKElements(arr, size, k);
    return 0;
}
// Output
// 50 88 96 
