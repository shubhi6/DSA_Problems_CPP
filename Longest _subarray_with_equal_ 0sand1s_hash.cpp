
#include <bits/stdc++.h>
using namespace std;

// Returns largest subarray with equal number of 0s and 1s

int maxLen(int arr[], int n)
{
    // Creates an empty hashMap hM

    unordered_map<int, int> hM;

    int sum = 0; // Initialize sum of elements
    int max_len = 0; // Initialize result
    int ending_index = -1;

    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;

    // Traverse through the given array

    for (int i = 0; i < n; i++) {
        // Add current element to sum

        sum += arr[i];

        // To handle sum=0 at last index

        if (sum == 0) {
            max_len = i + 1;
            ending_index = i;
        }

        // If this sum is seen before, then update max_len
        // if required

        if (hM.find(sum) != hM.end()) {
            if (max_len < i - hM[sum]) {
                max_len = i - hM[sum];
                ending_index = i;
            }
        }
        else // Else put this sum in hash table
            hM[sum] = i;
    }

    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == -1) ? 0 : 1;

    printf("%d to %d\n",
           ending_index - max_len + 1, ending_index);

    return max_len;
}

// Driver method

int main()
{
    int n, arr[n];
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the elements of array :";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    maxLen(arr, n);
    return 0;
    }
