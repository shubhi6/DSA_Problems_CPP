// Through this code we can find whether the subarray of two elements is present with their sum equal to given sum

// EXAMPLE:
// INPUT: arr=[ 2,5,8,12,30]  x=17
// OUTPUT=  Pair is present

// INPUT: arr=[ 1 2 3 5 15]  x=20
// OUTPUT=  Pair is present

// INPUT: arr=[ 3 8 13 18]  x=14
// OUTPUT=  Pair is not present
   

#include<iostream>
using namespace std;

bool ispair(int arr[], int n, int x)
{
    int i = 0, k = n - 1;
    while (i < k)
    {
        if (arr[i] + arr[k] == x)
            return true;
        else if (arr[i] + arr[k] > x)
            k--;
        else
            i++;
    }
    return false;
}

int main()
{
    int j, n, x;
    cout << "Enter size of array = ";
    cin >> n;

    // Declare an array of integers to store elements
    int arr[n];

    cout << "Enter elements of array = ";
    for (j = 0; j < n; j++)
        cin >> arr[j];

    cout << "Enter the sum = ";
    cin >> x;

    // Call the function and print the result
    if (ispair(arr, n, x))
        cout << "Pair is present";
    else
        cout << "Pair is not present";

    return 0;
}

