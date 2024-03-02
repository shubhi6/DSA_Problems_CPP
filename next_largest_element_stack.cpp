#include <bits/stdc++.h>
using namespace std;

void nextLargerElement(int arr[], int n) {
    vector<unordered_map<string, int>> s;

    for (int i = 0; i < n; i++) {
        while (s.size() > 0 && s[s.size() - 1]["value"] < arr[i]) {
            unordered_map<string, int> d = s[s.size() - 1];
            s.pop_back();
            arr[d["ind"]] = arr[i];
        }
        unordered_map<string, int> e;
        e["value"] = arr[i];
        e["ind"] = i;
        s.push_back(e);
    }

    while (s.size() > 0) {
        unordered_map<string, int> d = s[s.size() - 1];
        s.pop_back();
        arr[d["ind"]] = -1;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    nextLargerElement(arr, n);

    cout << "Next larger elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
