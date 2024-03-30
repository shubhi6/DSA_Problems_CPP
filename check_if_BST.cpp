// Check for BST

// A binary search tree (BST) is a node based binary tree data structure which has the following properties. 

// * The left subtree of a node contains only nodes with keys less than the node's key.
// * The right subtree of a node contains only nodes with keys greater than the node's key.
// * Both the left and right subtrees must also be binary search trees.

#include <bits/stdc++.h> 
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
  
bool isBSTUtil(struct Node* root, Node *&prev) 
{ 
    if (root) 
    { 
        if (!isBSTUtil(root->left, prev)) 
          return false; 
   
        if (prev != NULL && root->data <= prev->data) 
          return false; 
   
        prev = root; 
   
        return isBSTUtil(root->right, prev); 
    } 
   
    return true; 
} 
  
bool isBST(Node *root) 
{ 
   Node *prev = NULL; 
   return isBSTUtil(root, prev); 
} 
  
int main() 
{ 
    struct Node *root = new Node(3); 
    root->left     = new Node(2); 
    root->right     = new Node(5); 
    root->left->left = new Node(1); 
    root->left->right = new Node(4); 
  
    if (isBST(root)) 
        cout << "Is BST"; 
    else
        cout << "Not a BST"; 
  
    return 0; 
}

// Output:  
// Not a BST
