// Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression.

// Example: 

// Input: exp = “[()]{}{[()()]()}” 
// Output: Balanced
// Explanation: all the brackets are well-formed

// Input: exp = “[(])” 
// Output: Not Balanced 
// Explanation: 1 and 4 brackets are not balanced because 
// there is a closing ‘]’ before the closing ‘(‘

#include <bits/stdc++.h>
using namespace std;

bool areBracketsBalanced(string expr) {
    stack<char> temp;
    for (int i = 0; i < expr.length(); i++) {
        if (temp.empty()) {
            temp.push(expr[i]);
        }
        else if ((temp.top() == '(' && expr[i] == ')')
                || (temp.top() == '{' && expr[i] == '}')
                || (temp.top() == '[' && expr[i] == ']')) {
            temp.pop();
        }
        else {
            temp.push(expr[i]);
        }
    }
    return temp.empty();
}

int main() {
    string expr = "{()}[]";
    cout<<expr<<endl;
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}

