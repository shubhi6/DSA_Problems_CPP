// Problem: Given a stack data structure with push and pop operations,
// the task is to implement a queue using instances of stack data structure and operations on them.

// Solution: A queue can be implemented using two stacks. Let the queue to be implemented be q and stacks used to implement q are stack1 and stack2 respectively.


//.....................METHOD 1...........

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

