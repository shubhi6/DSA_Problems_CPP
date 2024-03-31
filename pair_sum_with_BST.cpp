#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
      int data;
      Node* left;
      Node* right;
      Node(int d)
      {
          data=d;
          left=NULL;
          right=NULL;
      }
};

class BinarySearchTree {
    public:
    Node *root;

    BinarySearchTree()
    {
        root = NULL;
    }

    void inorderUtil(Node* node)
    {
        if (node == NULL)
            return;

        inorderUtil(node->left);
        cout << node->data << " ";
        inorderUtil(node->right);
    }

    void inorder()
    {
        inorderUtil(this->root);
    }

    Node* insertRec(Node* root, int data)
    {
        if (root == NULL) {
            root = new Node(data);
            return root;
        }

        if (data < root->data)
            root->left = insertRec(root->left, data);
        else if (data > root->data)
            root->right = insertRec(root->right, data);

        return root;
    }

    void insert(int key)
    {
        root = insertRec(root, key);
    }

    vector<int> treeToList(Node* node, vector<int>& list)
    {
        if (node == NULL)
            return list;

        treeToList(node->left, list);
        list.push_back(node->data);
        treeToList(node->right, list);

        return list;
    }

    bool isPairPresent(Node* node, int target)
    {
        vector<int> a1;
        vector<int> a2 = treeToList(node, a1);

        int start = 0;
        int end = (int)a2.size() - 1;

        while (start < end) {
            if (a2[start] + a2[end] == target) {
                cout << "Pair Found: " << a2[start] << " + " << a2[end] << " = " << target << '\n';
                return true;
            }

            if (a2[start] + a2[end]  > target) {
                end--;
            }

            if (a2[start] + a2[end]  < target) {
                start++;
            }
        }

        cout << "No such values are found!\n";
        return false;
    }
};

int main()
{
    BinarySearchTree *tree = new BinarySearchTree();

    tree->insert(15);
    tree->insert(10);
    tree->insert(20);
    tree->insert(8);
    tree->insert(12);
    tree->insert(16);
    tree->insert(25);

    tree->isPairPresent(tree->root, 33);
}

