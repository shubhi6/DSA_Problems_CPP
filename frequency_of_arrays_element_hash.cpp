Given an array which may contain duplicates, print all elements and their frequencies.

Examples: 

Input :  arr[] = {10, 20, 20, 10, 10, 20, 5, 20}
Output : 10 3
         20 4
         5  1

Input : arr[] = {10, 20, 20}
Output : 10 1
         20 2 

#include <bits/stdc++.h>
using namespace std;

void frequencyNumber(int arr[],int size)
{

  // Creating a HashMap containing integer
  // as a key and occurrences as a value
  unordered_map<int,int>freqMap;

  for (int i=0;i<size;i++) {
    freqMap[arr[i]]++;
  }

  // Printing the freqMap
  for (auto it : freqMap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
}

int main()
{
 int size;
 cout<<"Enter the size of array : ";
    cin >> size;
    int *arr = new int[size]; // Dynamically allocate memory for the array
    cout<<"Enter the elements of array : ";

    for (int i = 0; i < size; i++)
        cin >> arr[i];
  frequencyNumber(arr,size);
}
