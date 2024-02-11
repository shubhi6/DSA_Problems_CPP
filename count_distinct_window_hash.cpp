Given an array of size n and an integer k, return the count of distinct numbers in all windows of size k. 
Example: 

Input: arr[] = {1, 2, 1, 3, 4, 2, 3};
       k = 4
Output: 3 4 4 3

Explanation:
First window is {1, 2, 1, 3}, count of distinct numbers is 3
Second window is {2, 1, 3, 4} count of distinct numbers is 4
Third window is {1, 3, 4, 2} count of distinct numbers is 4
Fourth window is {3, 4, 2, 3} count of distinct numbers is 3

Input: arr[] = {1, 2, 4, 4};
       k = 2
Output: 2 2 1

Explanation:
First window is {1, 2}, count of distinct numbers is 2
First window is {2, 4}, count of distinct numbers is 2
First window is {4, 4}, count of distinct numbers is 1
 

#include <iostream>
#include <unordered_map>
using namespace std;

void countDistinct(int arr[], int k, int n)
{
    // Creates an empty hashmap hm
    unordered_map<int, int> hm;

    int dist_count = 0;

    for (int i = 0; i < k; i++) {
        if (hm[arr[i]] == 0) {
            dist_count++;
        }
        hm[arr[i]] += 1;
    }

   
    cout << dist_count << endl;

    for (int i = k; i < n; i++) {
       
        if (hm[arr[i - k]] == 1) {
            dist_count--;
        }
        // reduce count of the removed element
        hm[arr[i - k]] -= 1;

        if (hm[arr[i]] == 0) {
            dist_count++;
        }
        hm[arr[i]] += 1;

        // Print count of current window
        cout << dist_count << endl;
    }
}

int main()
{
     int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    int arr[size];
     cout<<"Enter the elements of array : ";
     for(int i=0;i<size;i++)
     cin>>arr[i];
    int k ;
    cout<<"Enter the value of k : ";
    cin>>k;
    countDistinct(arr, k, size);

    return 0;
}
