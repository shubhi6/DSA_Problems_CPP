// To convert an infix to postfix expression refer to this article Infix to Postfix article. We use the same to convert Infix to Prefix.

// Step 1: Reverse the infix expression i.e A+B*C will become C*B+A. Note while reversing each '(' will become ')' and each ')' becomes '('.
// Step 2: Obtain the "nearly" postfix expression of the modified expression i.e CB*A+.
// Step 3: Reverse the postfix expression. Hence in our example prefix is +A*BC.
    
// Note that for Step 2, we don't use the postfix algorithm as it is. There is a minor change in the algorithm. 
//  We have to pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator.
// But here, we have to pop all the operators from the stack which are greater in precedence than that of the scanned operator.
// Only in the case of "^" operator, we pop operators from the stack which are greater than or equal to in precedence.

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostfix(string infix) {
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        else if (infix[i] == '(')
            char_stack.push('(');
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.pop();
        } else {
            if (isOperator(char_stack.top())) {
                if(infix[i] == '^') {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                } else {
                    while (getPriority(infix[i]) < getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                char_stack.push(infix[i]);
            }
        }
    }
    while(!char_stack.empty()) {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}

string infixToPrefix(string infix) {
    int l = infix.size();
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string s = ("x+y*z/w+u");
    cout << infixToPrefix(s) << std::endl;
    return 0;
}

