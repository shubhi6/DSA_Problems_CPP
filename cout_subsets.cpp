// Through this code we can find the subsets whose sum is equal to the target sum
// Example if arr={ 10,2,5,6,3} and target sum is 8 then a our output will be 2.
// Because {2,6} and {5,3} are two subsets whose sum is 8.

#include<iostream>
using namespace std;

int css(int arr[], int n, int sum) {
    if (sum == 0) 
        return 1;
    
    if (n == 0)
        return 0;

    // Include the current element in the subset
    int includeCurrent = css(arr, n - 1, sum - arr[n - 1]);

    // Exclude the current element from the subset
    int excludeCurrent = css(arr, n - 1, sum);

    return includeCurrent + excludeCurrent;
}

int main() {
    int n, sum;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    int countSubsets = css(arr, n, sum);

    cout << "Number of subsets with sum " << sum << ": " << countSubsets << endl;

    return 0;
}

