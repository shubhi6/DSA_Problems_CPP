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

