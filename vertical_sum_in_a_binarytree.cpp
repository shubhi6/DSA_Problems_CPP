//................. Vertical Sum in a Binary Tree...................

// Given a Binary Tree, find the vertical sum of the nodes that are in the same vertical line. Print all sums through different vertical lines.
// Examples: 
 

//       1
//     /   \
//   2      3
//  / \    / \
// 4   5  6   7

// The tree has 5 vertical lines
// Vertical-Line-1 has only one node 4 => vertical sum is 4 
// Vertical-Line-2: has only one node 2=> vertical sum is 2 
// Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12 
// Vertical-Line-4: has only one node 3 => vertical sum is 3 
// Vertical-Line-5: has only one node 7 => vertical sum is 7
So expected output is 4, 2, 12, 3 and 7 

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void verticalSumUtil(Node *node, int hd,
                     map<int, int> &Map)
{
    if (node == NULL) return;

    verticalSumUtil(node->left, hd-1, Map);
    Map[hd] += node->data;
    verticalSumUtil(node->right, hd+1, Map);
}

void verticalSum(Node *root)
{
    map < int, int> Map;
    map < int, int> :: iterator it;

    verticalSumUtil(root, 0, Map);

    for (it = Map.begin(); it != Map.end(); ++it)
    {
        cout << it->first << ": "
             << it->second << endl;
    }
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    cout << "Following are the values of vertical"
            " sums with the positions of the "
            "columns with respect to root\n";
    verticalSum(root);

    return 0;
}


// Output
// Following are the values of vertical sums with the positions of the columns with respect to root
// -2: 4
// -1: 2
// 0: 12
// 1: 11
// 2: 7
// 3: 9
