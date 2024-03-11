// ......................Preorder Traversal.........................
// Algorithm Preorder(tree)

// 1. Visit the root.
// 2. Traverse the left subtree, i.e., call Preorder(left->subtree)
// 3. Traverse the right subtree, i.e., call Preorder(right->subtree) 

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    return 0;
}

// Output

// Preorder traversal of binary tree is 
// 1 2 4 5 3 
