// Counting sort is a sorting technique based on keys between a specific range. 
// It works by counting the number of objects having distinct key values (kind of hashing). 
// Then doing some arithmetic to calculate the position of each object in the output sequence.

// Let us understand it with the help of an example.
// For simplicity, consider the data in the range 0 to 9. 
// Input data: 1, 4, 1, 2, 7, 5, 2
//   1) Take a count array to store the count of each unique object.
//   Index:     0  1  2  3  4  5  6  7  8  9
//   Count:     0  2  2  0   1  1  0  1  0  0

//   2) Modify the count array such that each element at each index 
//   stores the sum of previous counts. 
//   Index:     0  1  2  3  4  5  6  7  8  9
//   Count:     0  2  4  4  5  6  6  7  7  7

// The modified count array indicates the position of each object in 
// the output sequence.
 
//   3) Output each object from the input sequence followed by 
//   decreasing its count by 1.
//   Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
//   Put data 1 at index 2 in output. Decrease count by 1 to place 
//   next data 1 at an index 1 smaller than this index.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countSort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

int main()
{
    int n;
    cout << "Enter size of array = ";
    cin >> n;
    cout << "Enter elements of array = ";

    vector<int> arr(n); // Using vector instead of array
    for (int j = 0; j < n; j++)
        cin >> arr[j];

    countSort(arr); // Fix the function name here

    cout << "After sort : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

