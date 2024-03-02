// Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1's. 

// Example: 

// Input:
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// Output :
// 8
// Explanation : 
// The largest rectangle with only 1's is from 
// (1, 0) to (2, 3) which is
// 1 1 1 1
// 1 1 1 1 

// Input:
// 0 1 1
// 1 1 1
// 0 1 1      
// Output:
// 6
// Explanation : 
// The largest rectangle with only 1's is from 
// (0, 1) to (2, 2) which is
// 1 1
// 1 1
// 1 1

#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

int maxHist(int row[]) {
    stack<int> result;
    int top_val;
    int max_area = 0;
    int area = 0;
    int i = 0;
    while (i < C) {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
        else {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
        max_area = max(area, max_area);
    }
    return max_area;
}

int maxRectangle(int A[][C]) {
    int result = maxHist(A[0]);
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++)
            if (A[i][j])
                A[i][j] += A[i - 1][j];
        result = max(result, maxHist(A[i]));
    }
    return result;
}

int main() {
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

    cout << "Area of maximum rectangle is " << maxRectangle(A);

    return 0;
}
