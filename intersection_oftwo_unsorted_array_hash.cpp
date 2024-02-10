// Given two unsorted arrays, the task is to find intersection of two unsorted array using hash.
// Examples: 

// Input: a[] = {10,1,3,2 4, 5}, b[] = {9,2,3 6, 8} 
// Output: Intersection of arrays  = 2 3
// Input: a[] = { 7,7,8 4,4,5, 9}, b[] = { 7,4,5, 8} 
// Output: Intersection of arrays = 4  5  7  8

#include <bits/stdc++.h>
using namespace std;

void intersection(int a[],int b[],int m, int n)
{
  unordered_set<int> s(b,b+n);
  for(int i=0 ;i<m ;i++)
  if(s.find(a[i])!=s.end())
  cout<<a[i]<<" ";
}

int main()
{
 int n,m;
 cout<<"Enter the size of first array : ";
    cin >> m;
    cout<<"Enter the elements of array : ";
    int *a = new int[m]; // Dynamically allocate memory for the array

    for (int i = 0; i < m; i++)
        cin >> a[i];

 cout<<"Enter the size of second array : ";
    cin >> n;
    cout<<"Enter the elements of array : ";
    int *b = new int[n]; // Dynamically allocate memory for the array

    for (int i = 0; i < n; i++)
        cin >> b[i];
  intersection(a,b,m,n);
}
