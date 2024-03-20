..................Threaded Binary Tree..................

    The Inorder traversal of a Binary tree can either be done using recursion or with the use of an auxiliary stack.
    Threaded Binary Trees are used to make the inorder traversal faster and do it without stack and without recursion.
    A binary tree is made threaded by making all right child pointers that would normally be NULL point to the inorder successor of the node (if it exists).

// There are two types of threaded binary trees:

// 1. Single Threaded: Where a NULL right pointers is made to point to the inorder successor (if successor exists).

// 2. Double Threaded: Where both left and right NULL pointers are made to point to inorder predecessor and inorder successor respectively.
// The predecessor threads are useful for reverse inorder traversal and postorder traversal.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool rightThread;
};

Node* leftMost(Node *N) {
    if (N == NULL)
        return NULL;
    while (N->left != NULL)
        N = N->left;
    return N;
}

void inOrder(Node *root) {
    Node *cur = leftMost(root);
    while (cur != NULL) {
        cout << cur->data << " ";
        if (cur->rightThread)
            cur = cur->right;
        else
            cur = leftMost(cur->right);
    }
}

int main() {
    Node* root = new Node{1, NULL, NULL, false};
    root->left = new Node{2, NULL, NULL, false};
    root->right = new Node{3, NULL, NULL, false};
    root->left->left = new Node{4, NULL, NULL, false};
    root->left->right = new Node{5, NULL, NULL, true};
    root->right->left = new Node{6, NULL, NULL, false};
    root->right->right = new Node{7, NULL, NULL, false};
    root->left->right->right = root;

    cout << "Inorder traversal of the threaded binary tree: ";
    inOrder(root);

    return 0;
}
