// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a 
// number of contiguous bars whose heights are given in an array. For simplicity, assume that all bars have the same width and the width is 1 unit. 

// Example: 

// Input: histogram = {6, 2, 5, 4, 5, 1, 6}
// Output: 12

// Input: histogram = {3, 5, 1, 7, 5, 9}
// Output: 15

#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[], int n) {
    stack<int> s;
    int max_area = 0;
    int tp;
    int area_with_top;

    int i = 0;
    while (i < n) {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    while (s.empty() == false) {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

int main() {
    int hist[] = { 6, 2, 5, 4, 5, 1, 6 };
    int n = sizeof(hist) / sizeof(hist[0]);

    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}
