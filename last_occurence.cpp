// Given a sorted array arr[] with possibly duplicate elements, the task is to find index of the  last occurrence of an element x in the given array. 

// Examples: 

// Input : arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}, x = 5
// Output Last Occurrence = 5

// Input : arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125 }, x = 7

// Output : Last Occurrence = 6

#include<iostream>
using namespace std;

int lastocc(int arr[], int n, int x)
{
    int low = 0, high = n - 1, res = -1;
	while (low <= high) {

		// Normal Binary Search Logic
		int mid = (low + high) / 2;

		if (arr[mid] > x)
			high = mid - 1;
		else if (arr[mid] < x)
			low = mid + 1;

		// If arr[mid] is same as x, we
		// update res and move to the right
		// half.
		else {
			res = mid;
			low = mid + 1;
		}
	}
	return res;
}

int main()
{
    int j, n, x;
    cout << "Enter size of array = ";
    cin >> n;
    cout << "Enter elements of array = ";
    int arr[n];
    for (j = 0; j < n; j++)
        cin >> arr[j];
    cout << "Enter the element to be searched = ";
    cin >> x;
    cout << "Index of last occurrence of element is = ";
    cout << lastocc(arr, n, x);
}

