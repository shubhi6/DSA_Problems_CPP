//........................NAIVE APPROACH......................

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        int data = d;
        left = right = NULL;
    }
};

int height(Node* node) {
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(Node* root) {
    int lh;
    int rh;
    if (root == NULL)
        return 1;
    lh = height(root->left);
    rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}

// Output
// Tree is not balanced

//.......................EFFICIENT APPROACH............


#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* left;
	struct Node* right;
	Node(int k) {
		key = k;
		left = right = NULL;
	}
};

int isBalanced(Node* root) {
	if (root == NULL)
		return 0;
	int lh = isBalanced(root->left);
	if (lh == -1)
		return -1;
	int rh = isBalanced(root->right);
	if (rh == -1)
		return -1;

	if (abs(lh - rh) > 1)
		return -1;
	else
		return max(lh, rh) + 1;
}

int main() {
	Node* root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(30);
	root->right->left = new Node(15);
	root->right->right = new Node(20);

	if (isBalanced(root) > 0)
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}

// Output
// Balanced
