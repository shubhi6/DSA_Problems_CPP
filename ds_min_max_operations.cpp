// Problem: Design a Data Structure a SpecialQueue which supports following operations enqueue, deque, getMin() 
//or getMax() where getMin() operation takes O(1) time.
// Example: 
 

// Let the data to be inserted in queue be -
// 4, 2, 1, 6

// Operation     Queue       Output
// push(4)         4           -
// push(2)        4, 2         -
// push(1)       4, 2, 1       -
// getMin()      4, 2, 1       1
// push(6)      4, 2, 1, 6     -
// pop()         2, 1, 6       4
// pop()          1, 6         2
// pop()            6          1
// getMin()         6          6

// Notice the getMin() function call
// It returns the minimum element 
// of all the values present in the queue


#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MinMaxQueue {
public:
    queue<T> Q;
    deque<T> D;
    
    void enque_element(T element) {
        if (Q.size() == 0) {
            Q.push(element);
            D.push_back(element);
        }
        else {
            Q.push(element);
            while (!D.empty() && D.back() > element) {
                D.pop_back();
            }
            D.push_back(element);
        }
    }
    
    void deque_element() {
        if (Q.front() == D.front()) {
            Q.pop();
            D.pop_front();
        }
        else {
            Q.pop();
        }
    }
    
    T getMin() {
        return D.front();
    }
};

int main() {
    MinMaxQueue<int> k;
    int example[3] = { 1, 2, 4 };
    for (int i = 0; i < 3; i++) {
        k.enque_element(example[i]);
    }
    cout << k.getMin() << "\n";
    k.deque_element();
    cout << k.getMin() << "\n";
}

// Output: 
// 1
// 2
