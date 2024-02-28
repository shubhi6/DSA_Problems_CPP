//...................Stack in C++ STL..........

//The C++ STL offers a built-in class named stack for implementing the stack data structure easily and efficiently.
//This class provides almost all functions needed to perform the standard stack operations like push(), pop(), peek(), remove() etc.

//EXAMPLE:

//Output: 
//The stack is : 	1	5	20	30	10
//
//s.size() : 5
//s.top() : 1
//s.pop() : 	5	20	30	10


#include <iostream> 
#include <stack> 

using namespace std; 
  
void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    stack <int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 
  
    return 0; 
} 
