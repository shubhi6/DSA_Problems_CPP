#include <iostream>
#include <unordered_set>

using namespace std;

bool pair_sum(int arr[], int size, int sum) {
    unordered_set<int> h;

    for (int i = 0; i < size; i++) {
        if (h.find(sum - arr[i]) != h.end())
            return true;
        else
            h.insert(arr[i]);
    }
    return false;
}

int main() {
    int size, sum;
    cout << "Enter the size of array: ";
    cin >> size;
    int *arr = new int[size]; // Dynamically allocate memory for the array
    cout << "Enter the elements of array: ";

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter the sum value: ";
    cin >> sum;

    if (pair_sum(arr, size, sum))
        cout << "There exists a pair with the given sum." << endl;
    else
        cout << "No pair with the given sum exists." << endl;


    return 0;
}
