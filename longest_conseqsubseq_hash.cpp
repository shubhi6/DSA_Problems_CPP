// Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, 
// the consecutive numbers can be in any order. 

// Examples:  
// Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
// Output: 4
// Explanation: 
// The subsequence 1, 3, 4, 2 is the longest 
// subsequence of consecutive elements

// Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
// Output: 5
// Explanation: 
// The subsequence 36, 35, 33, 34, 32 is the longest 
// subsequence of consecutive elements.

#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;

   
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

 
    for (int i = 0; i < n; i++)
    {
        
        if (S.find(arr[i] - 1) == S.end())
        {
            
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

           
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
