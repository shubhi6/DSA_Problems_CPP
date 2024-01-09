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

