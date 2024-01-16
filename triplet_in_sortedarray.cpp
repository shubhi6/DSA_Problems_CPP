// Through this code we can find whether the subarray of two elements is present with their sum equal to given sum

// EXAMPLE:
// INPUT: arr=[ 2,5,8,12,30]  x=37
// OUTPUT=  Triplet is present

// INPUT: arr=[ 1 2 3 5 15]  x=20
// OUTPUT=  Triplet is present

// INPUT: arr=[ 3 8 13 18]  x=14
// OUTPUT=  Triplet is not present
   

#include <iostream>
#include <vector>

using namespace std;

bool ispair(int arr[], int n, int x, int si) {
    int i = si, k = n - 1;
    while (i < k) {
        if (arr[i] + arr[k] == x)
            return true;
        else if (arr[i] + arr[k] > x)
            k--;
        else
            i++;
    }
    return false;
}

bool istriplet(int arr[], int n, int x) {
    for (int i = 0; i < n - 2; i++)
        if (ispair(arr, n, x - arr[i], i + 1))
            return true;
    return false;
}

int main() {
    int n, x;

    cout << "Enter size of array = ";
    cin >> n;

    // Declare a vector to store elements
    vector<int> arr(n);

    cout << "Enter elements of array = ";
    for (int j = 0; j < n; j++)
        cin >> arr[j];

    cout << "Enter the sum = ";
    cin >> x;

    // Call the function and print the result
    if (istriplet(arr.data(), n, x))
        cout << "Triplet is present";
    else
        cout << "Triplet is not present";

    return 0;
}

