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
