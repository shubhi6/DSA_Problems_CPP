//.......................... Maximum width of Binary Tree...................

// Given a binary tree, the task is to find the maximum width of the given tree. Width of a tree is maximum of widths of all levels. 

// Example: 

// Input:
//              1
//           /   \
//        2      3
//     /   \       \
//  4     5       8 
//               /     \
//            6        7
// Output:  3
// Explanation: For the above tree, 
// width of level 1 is 1, 
// width of level 2 is 2, 
// width of level 3 is 3 
// width of level 4 is 2. 
// So the maximum width of the tree is 3.


#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int d) {
        this->data = d;
        this->left = this->right = NULL;
    }
};

int getWidth(node* root, int level);
int height(node* node);
int getMaxWidth(node* root);

int getMaxWidth(node* root) {
    int maxWidth = 0;
    int width;
    int h = height(root);
    int i;

    for (i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > maxWidth)
            maxWidth = width;
    }

    return maxWidth;
}

int getWidth(node* root, int level) {
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    else if (level > 1)
        return getWidth(root->left, level - 1)
            + getWidth(root->right, level - 1);
}

int height(node* node) {
    if (node == NULL)
        return 0;
    else {
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
    }
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(8);
    root->right->right->left = new node(6);
    root->right->right->right = new node(7);

    cout << "Maximum width is " << getMaxWidth(root) << endl;
    return 0;
}

