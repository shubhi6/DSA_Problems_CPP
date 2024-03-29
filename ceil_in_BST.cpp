Ceil in BST

// Given a binary tree and a key(node) value, find the ceil value for that particular key value.
// Ceil Value Node: Node with the smallest data larger than or equal to the key value.

// For example, Let's consider the Binary Tree below - 

//           8
//         /   \    
//       4      12
//     /  \    /  \
//    2    6  10   14

// Key: 11   Ceil: 12
// Key: 1    Ceil: 2
// Key: 6    Ceil: 6
// Key: 15   Ceil: -1

#include <bits/stdc++.h> 
using namespace std; 

class node { 
public: 
    int key; 
    node* left; 
    node* right; 
}; 

node* newNode(int key) 
{ 
    node* Node = new node(); 
    Node->key = key; 
    Node->left = NULL; 
    Node->right = NULL; 
    return (Node); 
} 

int Ceil(node* root, int input) 
{ 
    if (root == NULL) 
        return -1; 

    if (root->key == input) 
        return root->key; 

    if (root->key < input) 
        return Ceil(root->right, input); 

    int ceil = Ceil(root->left, input); 
    return (ceil >= input) ? ceil : root->key; 
} 

int main() 
{ 
    node* root = newNode(8); 

    root->left = newNode(4); 
    root->right = newNode(12); 

    root->left->left = newNode(2); 
    root->left->right = newNode(6); 

    root->right->left = newNode(10); 
    root->right->right = newNode(14); 

    for (int i = 0; i < 16; i++) 
        cout << i << " " << Ceil(root, i) << endl; 

    return 0; 
} 

Output
0 2
1 2
2 2
3 4
4 4
5 6
6 6
7 8
8 8
9 10
10 10
11 12
12 12
13 14
14 14
15 -1
Time complexity: O(logn) 

Auxiliary Space: O(logn) 



Algorithm:  

Imagine we are moving down the tree, and assume we are root node. 
The comparison yields three possibilities,

A) Root data is equal to key. We are done, root data is ceil value.

B) Root data < key value, certainly the ceil value can't be in left subtree. 
   Proceed to search on right subtree as reduced problem instance.

C) Root data > key value, the ceil value may be in left subtree. 
   We may find a node with is larger data than key value in left subtree, 
   if not the root itself will be ceil node.

