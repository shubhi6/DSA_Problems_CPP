// Algorithm:

// EVALUATE_PREFIX(STRING)
// Step 1: Put a pointer P at the end of the end
// Step 2: If character at P is an operand push it to Stack
// Step 3: If the character at P is an operator pop two 
//         elements from the Stack. Operate on these elements
//         according to the operator, and push the result 
//         back to the Stack
// Step 4: Decrement P by 1 and go to Step 2 as long as there
//         are characters left to be scanned in the expression.
// Step 5: The Result is stored at the top of the Stack, 
//         return it
// Step 6: End

#include <bits/stdc++.h>
using namespace std;

double evaluatePrefix(string exprsn) {
    stack<double> Stack;

    for (int j = exprsn.size() - 1; j >= 0; j--) {
        if (exprsn[j] == ' ')
            continue;

        if (isdigit(exprsn[j])) {
            double num = 0, i = j;
            while (j < exprsn.size() && isdigit(exprsn[j]))
                j--;
            j++;

            for (int k = j; k <= i; k++)
                num = num * 10 + double(exprsn[k] - '0');

            Stack.push(num);
        } else {
            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();
            switch (exprsn[j]) {
                case '+':
                    Stack.push(o1 + o2);
                    break;
                case '-':
                    Stack.push(o1 - o2);
                    break;
                case '*':
                    Stack.push(o1 * o2);
                    break;
                case '/':
                    Stack.push(o1 / o2);
                    break;
            }
        }
    }
    return Stack.top();
}

int main() {
    string exprsn = "+ 9 * 12 6";
    cout << evaluatePrefix(exprsn) << endl;
    return 0;
}
