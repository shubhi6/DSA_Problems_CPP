// Write a program to Convert Infix expression to Postfix.

// Infix expression: The expression of the form a operator b (a + b). When an operator is in-between every pair of operands.
// Postfix expression: The expression of the form a b operator (ab+). When an operator is followed by every pair of operands.

// Examples:

// Input: A + B * C + D
// Output: ABC*+D+

// Input: ((A + B) - C * (D / E)) + F
// Output: AB+CDE/*-F+  

#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
