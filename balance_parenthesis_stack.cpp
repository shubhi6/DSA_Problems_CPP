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

