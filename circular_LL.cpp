//...............Circular Linked Lists.........

 
 #include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
    int data; 
    struct Node *next; 
}; 

struct Node *addEnd(struct Node *last, int data) 
{ 
    if (last == NULL) 
    {
        struct Node *temp = new Node; 
        temp -> data = data; 
        last = temp; 
        last -> next = last; 
        return last; 
    }
    
    struct Node *temp = new Node; 
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
    last = temp; 
    return last; 
} 

void traverse(struct Node *last) 
{ 
    struct Node *p; 
    if (last == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
    p = last -> next; 
    do
    { 
        cout << p -> data << " "; 
        p = p -> next; 
    } 
    while(p != last->next); 
} 

int main() 
{ 
    struct Node *last = NULL; 
    last = addEnd(last, 6); 
    last = addEnd(last, 4); 
    last = addEnd(last, 2); 
    last = addEnd(last, 8); 
    last = addEnd(last, 12); 
    last = addEnd(last, 10); 
    traverse(last); 
    return 0; 
}



//Advantages of Circular Linked Lists:
 

//1. Any node can be a starting point.
//We can traverse the whole list by starting from any point.
//We just need to stop when the first visited node is visited again. 

//2. Useful for implementation of a queue.
//Unlike this implementation, we don’t need to maintain two pointers for front and rear if we use a circular linked list.
//We can maintain a pointer to the last inserted node and the front can always be obtained as the next of last.

//3. Circular lists are useful in applications to repeatedly go around the list.
//For example, when multiple applications are running on a PC,
//it is common for the operating system to put the running applications on a list and then to cycle through them,
//giving each of them a slice of time to execute,
//and then making them wait while the CPU is given to another application.
//It is convenient for the operating system to use a circular list so that,
//when it reaches the end of the list it can cycle around to the front of the list.

//4. Circular Doubly Linked Lists are used for implementation of advanced data structures like Fibonacci Heap.
