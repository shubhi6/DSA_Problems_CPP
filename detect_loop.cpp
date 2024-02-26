//Given a linked list, check if the linked list has a loop or not.
// The idea is to point the current node of the linked list to a node which is created. Whenever a node’s next is pointing to that node it means loop is there.

// Follow the steps below to solve the problem:

// A temporary node is created. 
// The next pointer of each node that is traversed is made to point to this temporary node. 
// This way we are using the next pointer of a node as a flag to indicate whether the node has been traversed or not. 
// Every node is checked to see if the next is pointing to a temporary node or not.
// In the case of the first node of the loop, the second time we traverse it this condition will be true, hence we find that loop exists. 
// If we come across a node that points to null then the loop doesn’t exist.

	
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key) {
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

void printList(Node* head) {
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

bool detectLoop(Node* head) {
	Node* temp = new Node;
	while (head != NULL) {
		if (head->next == NULL)
			return false;
		if (head->next == temp)
			return true;
		Node* next = head->next;
		head->next = temp;
		head = next;
	}
	return false;
}

int main() {
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = head->next->next;
	bool found = detectLoop(head);
	if (found)
		cout << "Loop Found";
	else
		cout << "No Loop";
	return 0;
}

