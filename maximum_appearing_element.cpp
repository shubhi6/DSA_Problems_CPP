// Given two arrays L[ ] and R[ ] of size N where L[i] and R[i] (0 ≤ L[i], R[i] < 106) denotes a range of numbers, the task is to find the maximum occurred integer in all the ranges. If more than one such integer exists, print the smallest one. 
// Through this we can find the maximum appearing elements.

// Thus 4 is the Most appeared Element in the Ranges
// Examples: 

// Input: L[ ] = {1, 4, 3, 1}, R[ ] = {15, 8, 5, 4}
// Output: 4

// Explanation: Overall ranges are: {1,2,3,4,5,6,7,8,9,10,11,12,13,14 15}, {4,5,6,7,8}, {3,4,5}, {1,2,3,4}. 

// In all these ranges, 4 appears the most times.

// Input: L[ ] = {1, 5, 9, 13, 21}, R[ ] = {15, 8, 12, 20, 24}
// Output: 5
// Explanation: Overall Ranges are: {1,2,3,4,5,6,7,8,9,10,11,12,13,14 15}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16,17,18,19,20},{21,22,23,24}
// In these ranges, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 all appear 2 times. The smallest number among all are 5.

#include <iostream>
using namespace std;

int maximumOccurredElement(int l[], int r[], int n)
{
    int freq[100]={0};
    for (int i = 0; i < n; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            freq[j]++;
        }
    }
    int res = 0;
    for (int i = 0; i < 100; i++) {
        if (freq[i] > freq[res])
            res = i;
    }
    cout<<"Maximum appearing elements is = ";
    return res;
}

int main()
{
	int j,n,L[n],R[n];
	cout<<"Enter size of array = ";
	cin>>n;
	cout<<"Enter elements of 1st array = ";
	for(j=0;j<n;j++)
	cin>>L[j];
	cout<<"Enter elements of 2nd array = ";
	for(j=0;j<n;j++)
	cin>>R[j];
	
    cout << maximumOccurredElement(L, R, n) << endl;
    return 0;
}
