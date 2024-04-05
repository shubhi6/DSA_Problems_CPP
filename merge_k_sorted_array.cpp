//.....................Merge K Sorted Arrays........................

// Given k sorted arrays of possibly different sizes, merge them and print the sorted output.
// Examples: 

// Input: k = 3 
//       arr[][] = { {1, 3},
//                   {2, 4, 6},
//                   {0, 9, 10, 11}} ;
// Output: 0 1 2 3 4 6 9 10 11 

// Input: k = 2
//       arr[][] = { {1, 3, 20},
//                   {2, 4, 6}} ;
// Output: 1 2 3 4 6 20 


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > ppi;

vector<int> mergeKArrays(vector<vector<int> > arr)
{
    vector<int> output;
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({ arr[i][0], { i, 0 } });

    while (pq.empty() == false) {
        ppi curr = pq.top();
        pq.pop();
        int i = curr.second.first;
        int j = curr.second.second;
        output.push_back(curr.first);
        if (j + 1 < arr[i].size())
            pq.push({ arr[i][j + 1], { i, j + 1 } });
    }

    return output;
}

int main()
{
    vector<vector<int> > arr{ { 2, 6, 12 }, { 1, 9 },{ 23, 34, 90, 2000 } };

    vector<int> output = mergeKArrays(arr);

    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";

    return 0;
}

// Output
// Merged array is 
// 1 2 6 9 12 23 34 90 2000 
