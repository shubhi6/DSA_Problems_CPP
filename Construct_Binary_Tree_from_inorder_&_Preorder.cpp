// ......................Construct Binary Tree from Inorder and Preorder.................

// Let us consider the below traversals:

// Inorder sequence: D B E A F C 
// Preorder sequence: A B D E C F
// subtree and elements on right in the right subtree. So we know the below structure now. 

//                  A
//                /   \
//              /       \
//            D B E     F C
// We recursively follow the above steps and get the following tree.

//          A
//        /   \
//      /       \
//     B         C
//    / \        /
//  /     \    /
// D       E  F
// Algorithm: 

1. Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick the next element in the next recursive call. 
2. Create a new tree node tNode with the data as the picked element. 
3. Find the picked element’s index in Inorder. Let the index be inIndex. 
4. Call buildTree for elements before inIndex and make the built tree as a left subtree of tNode. 
5. Call buildTree for elements after inIndex and make the built tree as a right subtree of tNode. 
6. return tNode.

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(char data) {
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

struct Node* buildTree(char in[], char pre[], int inStrt, int inEnd, unordered_map <char, int> & mp) {
	static int preIndex = 0;
	if (inStrt > inEnd)
		return NULL;
	char curr = pre[preIndex++];
	struct Node* tNode = newNode(curr);
	if (inStrt == inEnd)
		return tNode;
	int inIndex = mp[curr];
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp);
	return tNode;
}

struct Node* buldTreeWrap(char in[], char pre[], int len) {
	unordered_map<char, int> mp;
	for (int i = 0; i < len; i++)
		mp[in[i]] = i;
	return buildTree(in, pre, 0, len - 1, mp);
}

void printInorder(struct Node* node) {
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%c ", node->data);
	printInorder(node->right);
}

int main() {
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
	int len = sizeof(in) / sizeof(in[0]);
	struct Node* root = buldTreeWrap(in, pre, len);
	printf("Inorder traversal of the constructed tree is \n");
	printInorder(root);
}

Output

Inorder traversal of the constructed tree is 
D B E A F C 
