// Given an array, print the Next Greater Element (NGE) for every element. 

// The Next greater Element for an element x is the first greater element on the right side of x in the array.
// Elements for which no greater element exist, consider the next greater element as -1. 

// Example: 

// Input: arr[] = [ 4 , 5 , 2 , 25 ]
// Output:  4      -->   5
//                5      -->   25
//                2      -->   25
//               25     -->   -1
// Explanation: except 25 every element has an element greater than them present on the right side

// Input: arr[] = [ 13 , 7, 6 , 12 ]
// Output:  13      -->    -1
//                 7       -->     12
//                 6       -->     12
//                12      -->     -1
// Explanation: 13 and 12 don't have any element greater than them present on the right side

#include <bits/stdc++.h>
using namespace std;

void nextLargerElement(int arr[], int n) {
    vector<unordered_map<string, int>> s;

    for (int i = 0; i < n; i++) {
        while (s.size() > 0 && s[s.size() - 1]["value"] < arr[i]) {
            unordered_map<string, int> d = s[s.size() - 1];
            s.pop_back();
            arr[d["ind"]] = arr[i];
        }
        unordered_map<string, int> e;
        e["value"] = arr[i];
        e["ind"] = i;
        s.push_back(e);
    }

    while (s.size() > 0) {
        unordered_map<string, int> d = s[s.size() - 1];
        s.pop_back();
        arr[d["ind"]] = -1;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    nextLargerElement(arr, n);

    cout << "Next larger elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
