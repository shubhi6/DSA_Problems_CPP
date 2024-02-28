//.............Intersection of two linked list.............

//There are two singly linked lists in a system. By some programming error,
//the end node of one of the linked lists got linked to the second list, forming an inverted Y-shaped list.
//Write a program to get the point where two linked lists merge.

//.....................Method : Using the difference in node counts...................

//Get the count of the nodes in the first list, let the count be c1.
//Get the count of the nodes in the second list, let the count be c2.
//Get the difference of counts d = abs(c1 – c2)
//Now traverse the bigger list from the first node to d nodes so that from here onwards both the lists have an equal no of nodes
//Then we can traverse both lists in parallel till we come across a common node.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

int getCount(Node* head);

int _getIntesectionNode(int d, Node* head1, Node* head2);

int getIntesectionNode(Node* head1, Node* head2)
{
	int c1 = getCount(head1);
	int c2 = getCount(head2);
	int d;

	if (c1 > c2) {
		d = c1 - c2;
		return _getIntesectionNode(d, head1, head2);
	}
	else {
		d = c2 - c1;
		return _getIntesectionNode(d, head2, head1);
	}
}

int _getIntesectionNode(int d, Node* head1, Node* head2)
{
	Node* current1 = head1;
	Node* current2 = head2;

	for (int i = 0; i < d; i++) {
		if (current1 == NULL) {
			return -1;
		}
		current1 = current1->next;
	}

	while (current1 != NULL && current2 != NULL) {
		if (current1 == current2)
			return current1->data;

		current1 = current1->next;
		current2 = current2->next;
	}

	return -1;
}

int getCount(Node* head)
{
	Node* current = head;
	int count = 0;

	while (current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}

int main()
{
	Node* newNode;

	Node* head1 = new Node();
	head1->data = 10;

	Node* head2 = new Node();
	head2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	cout << "The node of intersection is " << getIntesectionNode(head1, head2);
}

//.......................Method : Use Hashing..........................
//Basically, we need to find a common node of two linked lists. So we hash all nodes of the first list and then check the second list.
//1) Create an empty hash set.
//2) Traverse the first linked list and insert all nodes’ addresses in the hash set.
//3) Traverse the second list. For every node check if it is present in the hash set. If we find a node in the hash set, return the node.


#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void MegeNode(Node* n1, Node* n2) {
    unordered_set<Node*> hs;
    while (n1 != NULL) {
        hs.insert(n1);
        n1 = n1->next;
    }
    while (n2) {
        if (hs.find(n2) != hs.end()) {
            cout << n2->data << endl;
            break;
        }
        n2 = n2->next;
    }
}

void Print(Node* n) {
    Node* curr = n;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* n1 = new Node(1);
    n1->next = new Node(2);
    n1->next->next = new Node(3);
    n1->next->next->next = new Node(4);
    n1->next->next->next->next = new Node(5);
    n1->next->next->next->next->next = new Node(6);
    n1->next->next->next->next->next->next = new Node(7);

    Node* n2 = new Node(10);
    n2->next = new Node(9);
    n2->next->next = new Node(8);
    n2->next->next->next = n1->next->next->next;

    Print(n1);
    Print(n2);

    MegeNode(n1,n2);

    return 0;
}

