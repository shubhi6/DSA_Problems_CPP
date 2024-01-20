// Merge Overlapping Intervals Space Optimized Approach
// The above solution requires O(n) extra space for the stack. We can avoid the use of extra space by doing merge operations in place. Below are detailed steps. 

// Follow the steps mentioned below to implement the approach:

// Sort all intervals in increasing order of start time.
// Traverse sorted intervals starting from the first interval, 
// Do the following for every interval.
// If the current interval is not the first interval and it overlaps with the previous interval,
//  then merge it with the previous interval. Keep doing it while the interval overlaps with the previous one.         
//  Otherwise, Add the current interval to the output list of intervals.

#include <iostream>
#include <algorithm>
using namespace std;

// An Interval
struct Interval {
    int s, e;
};

// Function used in sort
bool mycomp(Interval a, Interval b) { return a.s < b.s; }

void mergeIntervals(Interval arr[], int n) {
    // Sort Intervals in increasing order of start time
    sort(arr, arr + n, mycomp);

    int index = 0; // Stores index of last element in output array (modified arr[])

    // Traverse all input Intervals
    for (int i = 1; i < n; i++) {
        // If this is not the first Interval and overlaps with the previous one
        if (arr[index].e >= arr[i].s) {
            // Merge previous and current Intervals
            arr[index].e = max(arr[index].e, arr[i].e);
        } else {
            index++;
            arr[index] = arr[i];
        }
    }

    // Now arr[0..index] stores the merged Intervals
    cout << "\nThe Merged Intervals are: ";
    for (int i = 0; i <= index; i++)
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}

// Driver program
int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    Interval arr[n];
    cout << "Enter elements of array (start and end for each interval): ";
    for (int j = 0; j < n; j++)
        cin >> arr[j].s >> arr[j].e;

    mergeIntervals(arr, n);
    return 0;
}

