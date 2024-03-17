// ..............................Finding LCA in Binary Tree..............................

// Given a Binary Tree and the value of two nodes n1 and n2. The task is to find the lowest common ancestor of the nodes n1 and n2 in the given Binary Tree.

  //             1
  //        /         \
  //       2           3
  //   /       \    /      \
  // 4           5 6         7     

//........................NAIVE SOLUTION.................

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};

Node* newNode(int k) {
    Node* temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

bool findPath(Node* root, vector<int>& path, int k) {
    if (root == NULL)
        return false;
    path.push_back(root->key);
    if (root->key == k)
        return true;
    if ((root->left && findPath(root->left, path, k)) || 
        (root->right && findPath(root->right, path, k)))
        return true;
    path.pop_back();
    return false;
}

int findLCA(Node* root, int n1, int n2) {
    vector<int> path1, path2;
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);

    return 0;
}

// Output:
// LCA(4, 5) = 2
// LCA(4, 6) = 1
// LCA(3, 4) = 1
// LCA(2, 4) = 2


//..................EFFICIENT SOLUTION.....................

#include <iostream>
using namespace std;

struct Node {
    struct Node *left, *right;
    int key;
};

Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->key == n1 || root->key == n2)
        return root;

    Node* left_lca = findLCA(root->left, n1, n2);
    Node* right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca)
        return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;

    return 0;
}



// Output:
// LCA(4, 5) = 2
// LCA(4, 6) = 1
// LCA(3, 4) = 1
// LCA(2, 4) = 2

