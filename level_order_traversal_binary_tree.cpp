// ........................Level Order Traversal of a Binary Tree.............................

// We have seen the three basic traversals(Preorder, postorder, and Inorder) of a Binary Tree. 
// We can also traverse a Binary Tree using the Level Order Traversal.

// In the Level Order Traversal, the binary tree is traversed level-wise starting from the first to last level sequentially.

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

Node* newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printLevelOrder(Node *root) {
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left != NULL)
            q.push(node->left);
        
        if (node->right != NULL)
            q.push(node->right);
    }
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}

// Output:
// 1 2 3 4 5

