// Given an unsorted array, count all distinct elements in it.
// Examples: 

// Input :   arr[] = {10, 20, 20, 10, 30, 10}
// Output : 3
// There are three distinct elements 10, 20 and 30.

// Input :   arr[] = {10, 20, 20, 10, 20}
// Output : 2

#include <unordered_set>
#include <iostream>
using namespace std;

// This function prints all distinct elements
int countDistinct(int arr[], int n) {
    // Creates an empty hashset
    unordered_set<int> s;

    // Traverse the input array
    int res = 0;
    for (int i = 0; i < n; i++) {
        // If not present, then put it in
        // hashtable and increment result
        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
            res++;
        }
    }

    return res;
}

// Driver program to test above function
int main() {
    int n;
    cout<<"Enter the size of array : ";
    cin >> n;
    int *arr = new int[n]; // Dynamically allocate memory for the array
    cout<<"Enter the elements of array : ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << countDistinct(arr, n);

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
