// ...................Postorder Traversal.................
// Algorithm Postorder(tree)

// 1. Traverse the left subtree, i.e., call Postorder(left->subtree)
// 2. Traverse the right subtree, i.e., call Postorder(right->subtree)
// 3. Visit the root

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout << node->data << " ";
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}

Output 
Postorder traversal of binary tree is 
4 5 2 3 1 
