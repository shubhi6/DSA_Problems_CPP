
// Given an array of distinct elements, find previous greater element for every element. If previous greater element does not exist, print -1.

// Examples: 

// Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
// Output :         -1, 10, 4, -1, -1, 40, 40

// Input : arr[] = {10, 20, 30, 40}
// Output :        -1, -1, -1, -1

// Input : arr[] = {40, 30, 20, 10}
// Output :        -1, 40, 30, 20


//.............NAIVE METHOD..........

#include <bits/stdc++.h>
using namespace std;

void prevGreater(int arr[], int n)
{ 
    cout << "-1, ";

    for (int i = 1; i < n; i++) {
        int j;
        for (j = i-1; j >= 0; j--) {
            if (arr[i] < arr[j]) {
                cout << arr[j] << ", ";
                break;
            }             
        }
        if (j == -1)
            cout << "-1, ";
    }
}

int main()
{
    int arr[] = { 10, 4, 2, 20, 40, 12, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    prevGreater(arr, n);
    return 0;
}


//...........EFFICIENT METHOD...........

#include <bits/stdc++.h>
using namespace std;

void prevGreater(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout << "-1, ";
    for (int i = 1; i < n; i++) {
        while (!s.empty() && s.top() < arr[i])
            s.pop();
        s.empty() ? cout << "-1, " : cout << s.top() << ", ";
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = { 10, 4, 2, 20, 40, 12, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    prevGreater(arr, n);
    return 0;
}

