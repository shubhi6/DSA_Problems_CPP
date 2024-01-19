// Given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. Traverse array only once.
// Examples: 

// Input :  arr[] = [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
// Output : arr[] = [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 

// Input :  arr[] = [1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1] 
// Output : arr[] = [0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1]  

#include <iostream>
using namespace std;

void segposneg(int arr[], int n)
{
    int type0 = 0;
    int type1 = n - 1;

    while (type0 < type1) {
        if (arr[type0] < 0) {
            swap(arr[type0], arr[type1]);
            type1--;
        }
        else {
            type0++;
        }
    }
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
    
    segposneg(arr, n);

    cout << "Segregated array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}

