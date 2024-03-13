//....................Size of a Binary Tree...............

// Algorithm: 

// size(tree)
// 1. If tree is empty then return 0
// 2. Else
//      (a) Get the size of left subtree recursively  i.e., call 
//           size( tree->left-subtree)
//      (a) Get the size of right subtree recursively  i.e., call 
//           size( tree->right-subtree)
//      (c) Calculate size of the tree as following:
//             tree_size  =  size(left-subtree) + size(right-
//                                subtree) + 1
//      (d) Return tree_size

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data) {
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}

int size(node* node) {
    if (node == NULL)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));
}

int main() {
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Size of the tree is " << size(root);
    return 0;
}

