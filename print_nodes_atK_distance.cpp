// ...........................Print Nodes at K Distance.....................

// Given a root of a tree, and an integer k. Print all the nodes which are at k distance from root. 
// For example, in the below tree, 4, 5 & 8 are at distance 2 from root. 

//             1
//           /   \
//         2      3
//       /  \    /
//     4     5  8 

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void printKDistant(node *root , int k)
{
	if(root == NULL|| k < 0 )
		return;
	if( k == 0 )
	{
		cout << root->data << " ";
		return;
	}
	
	printKDistant( root->left, k - 1 ) ;
	printKDistant( root->right, k - 1 ) ;
}

int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(8);
	
	printKDistant(root, 2);
	return 0;
}

// Output
// 4 5 8 
