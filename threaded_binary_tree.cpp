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
