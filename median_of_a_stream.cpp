// Median of a Stream

// Given that integers are read from a data stream. Find median of elements read so for in an efficient way.
// For simplicity assume, there are no duplicates. For example, let us consider the stream 5, 15, 1, 3 ... 
 

// After reading 1st element of stream - 5 -> median - 5
// After reading 2nd element of stream - 5, 15 -> median - 10
// After reading 3rd element of stream - 5, 15, 1 -> median - 5
// After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...

#include <bits/stdc++.h>
using namespace std;

void streamMed(int A[], int n)
{
    priority_queue<int> g, s;

    for (int i = 0; i < n; i++) {
        s.push(A[i]);
        int temp = s.top();
        s.pop();

        g.push(-1 * temp);
        if (g.size() > s.size()) {
            temp = g.top();
            g.pop();
            s.push(-1 * temp);
        }
        if (g.size() != s.size())
            cout << (double)s.top() << "\n";
        else
            cout << (double)((s.top() * 1.0 - g.top() * 1.0) / 2) << "\n";
    }
}

int main()
{
    int A[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
    int N = sizeof(A) / sizeof(A[0]);
    streamMed(A, N);
    return 0;
}
// Output

// 5
// 10
// 5
// 4
// 3
// 4
// 5
// 6
// 7
// 6.5
// 7
// 6.5
