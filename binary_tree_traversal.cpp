//................Binary Tree Traversals..................


// Unlike linear data structures (Array, Linked List, Queues, Stacks, etc.), 
// which have only one logical way to traverse them, trees can be traversed in different ways. 
// Following are the generally used ways for traversing trees:

// Example Tree

// Inorder (Left, Root, Right) : 4 2 5 1 3
// Preorder (Root, Left, Right) : 1 2 4 5 3.
// Postorder (Left, Right, Root) : 4 5 2 3 1



#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
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
    struct Node *root = new Node(1);
    root->left    = new Node(2);
    root->right    = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 

    cout << "Preorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root); 

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    return 0;
}

