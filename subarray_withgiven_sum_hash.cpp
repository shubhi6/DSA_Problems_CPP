Given an unsorted array arr of nonnegative integers and an integer sum, find a continuous subarray which adds to a given sum. 
There may be more than one subarrays with sum as the given sum, print first such subarray. 
Examples : 

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Output: Sum found between indexes 2 and 4
Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33
 

Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Output: Sum found between indexes 1 and 4
Sum of elements between indices 1 and 4 is 4 + 0 + 0 + 3 = 7

 

Input: arr[] = {1, 4}, sum = 0
Output: No subarray found
There is no subarray with 0 sum

#include <iostream>
using namespace std;

int subArraySum(int arr[], int n, int sum)
{

    int curr_sum = arr[0], start = 0, i;

    for (i = 1; i <= n; i++) {
        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        if (curr_sum == sum) {
            cout << "Sum found between indexes "
                 << start << " and " << i - 1;
            return 1;
        }

        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }

    cout << "No subarray found";
    return 0;
}

// Driver Code
int main()
{
    int n, sum;
    cout << "Enter the size of array: ";
    cin >> n;
    int *arr = new int[n]; // Dynamically allocate memory for the array
    cout << "Enter the elements of array: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the sum value: ";
    cin >> sum;
    subArraySum(arr, n, sum);
    return 0;
}
