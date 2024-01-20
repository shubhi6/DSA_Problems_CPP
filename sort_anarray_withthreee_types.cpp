// Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array. 
// The functions should put all 0s first, then all 1s and all 2s in last.
// Examples: 
 

// Input: {0, 1, 2, 0, 1, 2}
// Output: {0, 0, 1, 1, 2, 2}

// Input: {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
// Output: {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}

#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void sortArr(int arr[], int n)
{
    int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (i = 0; i < n; i++) {
        switch (arr[i]) {
        case 0:
            cnt0++;
            break;
        case 1:
            cnt1++;
            break;
        case 2:
            cnt2++;
            break;
        }
    }

 i=0;
    while (cnt0 > 0) {
        arr[i++] = 0;
        cnt0--;
    }
    while (cnt1 > 0) {
        arr[i++] = 1;
        cnt1--;
    }
    while (cnt2 > 0) {
        arr[i++] = 2;
        cnt2--;
    }

   
    printArr(arr, n);
}


int main()
{
    int j, n;
    cout << "Enter size of array = ";
    cin >> n;
    cout << "Enter elements of array = ";
    int arr[n];
    for (j = 0; j < n; j++)
    cin >> arr[j];

    sortArr(arr, n);

    return 0;
}
