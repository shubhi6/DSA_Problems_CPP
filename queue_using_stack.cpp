// Problem: Given a stack data structure with push and pop operations,
// the task is to implement a queue using instances of stack data structure and operations on them.

// Solution: A queue can be implemented using two stacks. Let the queue to be implemented be q and stacks used to implement q are stack1 and stack2 respectively.


//.....................METHOD 1...........

// Method 1 (By making enQueue operation costly): This method makes sure that oldest entered element(element inserted first) is always at the top of stack1,
// so that deQueue operation just pops from stack1. To put the element at top of stack1, stack2 is used. The idea is to while pushing an element,
// first move all elements from stack1 to stack2, insert the new element to stack1 and then again move all elements from stack2 to stack1. 
// Below is the implementation of both enQueue() and deQueue() operations:
// enQueue(q, x)
//   1) While stack1 is not empty, push everything from stack1 to stack2.
//   2) Push x to stack1 (assuming size of stacks is unlimited).
//   3) Push everything back to stack1.
// Here the time complexity will be O(n)

// deQueue(q)
//   1) If stack1 is empty then print an error
//   2) Pop an item from stack1 and return it
// Here time complexity will be O(1)


#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enQueue(int x)
    {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue()
    {
        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }
        int x = s1.top();
        s1.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}


//...............METHOD 2.................

#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enQueue(int x)
    {
        s1.push(x);
    }

    int deQueue()
    {
        if (s1.empty() && s2.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}

