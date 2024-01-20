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

