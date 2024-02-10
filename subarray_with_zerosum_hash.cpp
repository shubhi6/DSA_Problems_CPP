Given an array of positive and negative numbers, find if there is a subarray (of size at-least one) with 0 sum.
Examples : 
Input: {4, 2, -3, 1, 6}
Output: true 
Explanation:
There is a subarray with zero sum from index 1 to 3.

Input: {4, 2, 0, 1, 6}
Output: true

Explanation :  

The third element is zero. A single element is also a sub-array. 

Input: {-3, 2, 3, 1, 6}
Output: false

#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sumSet;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0|| sumSet.find(sum)!= sumSet.end())
            return true;

        sumSet.insert(sum);
    }
    return false;
}

// Driver code
int main()
{
     int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *arr = new int[n]; // Dynamically allocate memory for the array
    cout << "Enter the elements of array: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (subArrayExists(arr, n))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
    }
