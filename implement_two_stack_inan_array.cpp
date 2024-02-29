// Create a data structure twoStacks that represent two stacks.
// Implementation of twoStacks should use only one array, i.e., both stacks should use the same array for storing elements. 

// Following functions must be supported by twoStacks.

// push1(int x) --> pushes x to first stack 
// push2(int x) --> pushes x to second stack
// pop1() --> pops an element from first stack and return the popped element 
// pop2() --> pops an element from second stack and return the popped element
// Implementation of twoStack should be space efficient.

//............NAIVE METHOD...............

#include <bits/stdc++.h>
using namespace std;

struct TwoStacks { 
    int* arr; 
    int cap; 
    int top1, top2; 
    
    TwoStacks(int n) 
    { 
        cap = n; 
        arr = new int[n]; 
        top1 = n / 2 + 1; 
        top2 = n / 2; 
    } 
  
    void push1(int x) 
    { 
        
        if (top1 > 0) { 
            top1--; 
            arr[top1] = x; 
        } 
        else { 
            cout << "Stack Overflow"
                 << " By element :" << x << endl; 
            return; 
        } 
    } 
  
    void push2(int x) 
    { 
        if (top2 < cap - 1) { 
            top2++; 
            arr[top2] = x; 
        } 
        else { 
            cout << "Stack Overflow"
                 << " By element :" << x << endl; 
            return; 
        } 
    } 
   
    int pop1() 
    { 
        if (top1 <= cap / 2) { 
            int x = arr[top1]; 
            top1++; 
            return x; 
        } 
        else { 
            cout << "Stack UnderFlow"; 
            exit(1); 
        } 
    } 
   
    int pop2() 
    { 
        if (top2 >= cap / 2 + 1) { 
            int x = arr[top2]; 
            top2--; 
            return x; 
        } 
        else { 
            cout << "Stack UnderFlow"; 
            exit(1); 
        } 
    } 
}; 
  
int main() 
{ 
    TwoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is: " << ts.pop1() << endl; 
    ts.push2(40); 
    cout << "Popped element from stack2 is: " << ts.pop2() << endl; 
    return 0; 
}

// Output
// Stack Overflow By element : 7
// Popped element from stack1 is : 11
// Stack Overflow By element : 40
// Popped element from stack2 is : 15

//..............EFFICIENT METHOD.............



#include <bits/stdc++.h>
using namespace std;

struct TwoStacks { 
    int* arr; 
    int cap; 
    int top1, top2; 
    
    TwoStacks(int n)  
    { 
        cap = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = cap; 
    } 
  
    void push1(int x) 
    { 
        if (top1 < top2 - 1) { 
            top1++; 
            arr[top1] = x; 
        } 
        else { 
            cout << "Stack Overflow"; 
            exit(1); 
        } 
    } 
  
    void push2(int x) 
    { 
        if (top1 < top2 - 1) { 
            top2--; 
            arr[top2] = x; 
        } 
        else { 
            cout << "Stack Overflow"; 
            exit(1); 
        } 
    } 
  
    int pop1() 
    { 
        if (top1 >= 0) { 
            int x = arr[top1]; 
            top1--; 
            return x; 
        } 
        else { 
            cout << "Stack UnderFlow"; 
            exit(1); 
        } 
    } 
  
    int pop2() 
    { 
        if (top2 < cap) { 
            int x = arr[top2]; 
            top2++; 
            return x; 
        } 
        else { 
            cout << "Stack UnderFlow"; 
            exit(1); 
        } 
    } 
};
  
int main() 
{ 
    TwoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is "<<ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is "<< ts.pop2(); 
    return 0; 
}

// Output
// Popped element from stack1 is 11
// Popped element from stack2 is 40
