// Evaluation of Postfix Expression Using Stack:
// Follow the steps mentioned below to evaluate postfix expression using stack:

// * Create a stack to store operands (or values). 
// * Scan the given expression from left to right and do the following for every scanned element. 
//   ->If the element is a number, push it into the stack 
//   ->If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack 
// * When the expression is ended, the number in the stack is the final answer                                                                                                            

#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int top;
    unsigned capacity;
    int* array;
};

Stack* createStack(unsigned capacity) {
    Stack* stack = new Stack();
    if (!stack) return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = new int[(stack->capacity * sizeof(int))];
    if (!stack->array) return NULL;
    return stack;
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int peek(Stack* stack) {
    return stack->array[stack->top];
}

int pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(Stack* stack, int op) {
    stack->array[++stack->top] = op;
}

int evaluatePostfix(char* exp) {
    Stack* stack = createStack(strlen(exp));
    int i;
    if (!stack) return -1;
    for (i = 0; exp[i]; ++i) {
        if (exp[i] == ' ') continue;
        else if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
            push(stack, num);
        }
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]) {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2 / val1); break;
            }
        }
    }
    return pop(stack);
}

int main() {
    char exp[] = "100 200 + 2 / 5 * 7 +";
    cout << evaluatePostfix(exp);
    return 0;
}


// Example: 

// Input: str = "2 3 1 * + 9 -"
// Output: -4
// Explanation: 

// Scan 2, it's a number, so push it to stack. Stack contains '2' 
// Scan 3, again a number, push it to stack, stack now contains '2 3' (from bottom to top) 
// Scan 1, again a number, push it to stack, stack now contains '2 3 1' 
// Scan *, it's an operator, pop two operands from stack, apply the * operator on operands, we get 3*1 which results in 3. We push the result 3 to stack. The stack now becomes '2 3'. 
// Scan +, it's an operator, pop two operands from stack, apply the + operator on operands, we get 3 + 2 which results in 5. We push the result 5 to stack. The stack now becomes '5'. 
// Scan 9, it's a number, so we push it to the stack. The stack now becomes '5 9'. 
// Scan -, it's an operator, pop two operands from stack, apply the - operator on operands, we get 5 - 9 which results in -4. We push the result -4 to the stack. The stack now becomes '-4'. 
// There are no more elements to scan, we return the top element from the stack (which is the only element left in a stack).
// Input: str = "100 200 + 2 / 5 * 7 +"
// Output: 757
