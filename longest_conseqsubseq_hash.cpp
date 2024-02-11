#include <bits/stdc++.h>
using namespace std;

// Returns length of the longest
// contiguous subsequence
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;

    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

    // check each possible sequence from
    // the start then update optimal length
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

// Driver code
int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
     cout<<"Enter the elements of array : ";
     for(int i=0;i<n;i++)
     cin>>arr[i];

    cout << "Length of the Longest contiguous subsequence "
            "is "
         << findLongestConseqSubseq(arr, n);
    return 0;
}
