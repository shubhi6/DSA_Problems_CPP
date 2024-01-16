// Through this code we can find the repeating element in the array, there are certain rules which should be taken care of :-
// 1. O(n) should be the time complexity.
// 2. O(1) should be the space.
// 3. No modifications can be done to the original array.

// * Array size should be greater than 2
// * Only one elements repeats (any number of times).
// * All the elements from 0 to max(arr) are presnet.

// Therefore 0 <= max(arr) <= n-2.

// EXAMPLE:
// INPUT: Arr[] : { 0,2,1,3,2,2}
// OUTPUT: Repeating element = 2

// INPUT: Arr[] : { 1,2,3,0,3,4,5}
// OUTPUT: Repeating element = 3


#include<iostream>
using namespace std;

int findrepeating(int arr[], int n) {
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];

    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    int j, n;
    cout << "Enter size of array = ";
    cin >> n;
    cout << "Enter elements of array = ";
    int arr[n];
    for (j = 0; j < n; j++)
    cin >> arr[j];
    cout << "Repeating element = ";
    cout << findrepeating(arr, n);
}

