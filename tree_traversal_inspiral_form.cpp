........................Tree Traversal in Spiral Form........................

Write a function to print spiral order traversal of a tree. For below tree, function should print 1, 2, 3, 4, 5, 6, 7. 
 

//........................METHOD - 1 : (Recursive) 

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void printGivenLevel(struct node* root, int level, int ltr);
int height(struct node* node);
struct node* newNode(int data);
void printSpiral(struct node* root);

void printSpiral(struct node* root) {
    int h = height(root);
    int i;
    bool ltr = false;
    for(i = 1; i <= h; i++) {
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
    }
}

void printGivenLevel(struct node* root, int level, int ltr) {
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        if (ltr) {
            printGivenLevel(root->left, level - 1, ltr);
            printGivenLevel(root->right, level - 1, ltr);
        } else {
            printGivenLevel(root->right, level - 1, ltr);
            printGivenLevel(root->left, level - 1, ltr);
        }
    }
}

int height(struct node* node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

struct node* newNode(int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of binary tree is \n");
    printSpiral(root);
    return 0;
}

Output
Spiral Order Traversal Of The Tree Is :
1  2  3  4  5  6  7  

//..............METHOD - 2 : (Iterative)................. 

#include <iostream>
#include <stack>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

void printSpiral(struct node* root)
{
    if (root == NULL)
        return;

    stack<struct node*> s1;
    stack<struct node*> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            struct node* temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        while (!s2.empty()) {
            struct node* temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}

struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is \n";
    printSpiral(root);

    return 0;
}

Output
Spiral Order Traversal Of The Tree Is :
1  2  3  4  5  6  7  
