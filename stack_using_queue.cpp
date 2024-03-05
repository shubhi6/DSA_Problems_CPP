// Problem: Given a Queue data structure that supports standard operations like enqueue() and dequeue().
// We need to implement a Stack data structure using only instances of Queue and queue operations allowed on the instances.

//......................METHOD 1..................

// Method 1 (By making push operation costly): This method makes sure that newly entered element is always at the front of 'q1',
// so that pop operation just dequeues from 'q1'. The queue, 'q2' is used to put every new element at front of 'q1'.
// push(s, x) // x is the element to be pushed and s is stack
//   1) Enqueue x to q2
//   2) One by one dequeue everything from q1 and enqueue to q2.
//   3) Swap the names of q1 and q2 
// Swapping of names is done to avoid one more  
// movement of all elements from q2 to q1. 

pop(s)
  1) Dequeue an item from q1 and return it.

#include<bits/stdc++.h>
using namespace std;

class Stack
{ 
    queue<int> q1, q2;
    int curr_size;

    public:
    Stack()
    {
        curr_size = 0;
    }

    void push(int x)
    {
        curr_size++;
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop(){
        if (q1.empty())
            return ;
        q1.pop();
        curr_size--;
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size()
    {
        return curr_size;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size() << endl;
    return 0;
}


// Output :
// current size: 3
// 3
// 2
// 1
// current size: 1


//...................METHOD 2....................

#include<bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2;
    int curr_size;

    public:
    Stack()
    {
        curr_size = 0;
    }

    void pop()
    {
        if (q1.empty())
            return;

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        curr_size--;

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void push(int x)
    {
        q1.push(x);
        curr_size++;
    }

    int top()
    {
        if (q1.empty())
            return -1;

        while( q1.size() != 1 )
        {
           q2.push(q1.front());
           q1.pop();
        } 
        
        int temp = q1.front();
        
        q1.pop();
     
        q2.push(temp);

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return temp;
    }

    int size()
    {
        return curr_size;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "current size: " << s.size() << endl;
    return 0;
}

// Output :
// current size: 3
// 3
// 2
// 1
// current size: 1


