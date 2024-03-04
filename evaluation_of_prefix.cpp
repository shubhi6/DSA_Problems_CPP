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
