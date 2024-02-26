// Given a Linked List of integers, 
// write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list.
// Also, keep the order of even and odd numbers the same.

// Examples: 

// Input: 17->15->8->12->10->5->4->1->7->6->NULL
// Output: 8->12->10->4->6->17->15->5->1->7->NULL

// Input: 8->12->10->5->4->1->6->NULL
// Output: 8->12->10->4->6->5->1->NULL

// If all numbers are even then do not change the list
// Input: 8->12->10->NULL
// Output: 8->12->10->NULL

// If all numbers are odd then do not change the list
// Input: 1->3->5->7->NULL
// Output: 1->3->5->7->NULL

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void segregateEvenOdd(struct Node** head_ref) {
	Node* evenStart = NULL;
	Node* evenEnd = NULL;
	Node* oddStart = NULL;
	Node* oddEnd = NULL;
	Node* currNode = *head_ref;

	while (currNode != NULL) {
		int val = currNode->data;
		if (val % 2 == 0) {
			if (evenStart == NULL) {
				evenStart = currNode;
				evenEnd = evenStart;
			} else {
				evenEnd->next = currNode;
				evenEnd = evenEnd->next;
			}
		} else {
			if (oddStart == NULL) {
				oddStart = currNode;
				oddEnd = oddStart;
			} else {
				oddEnd->next = currNode;
				oddEnd = oddEnd->next;
			}
		}
		currNode = currNode->next;
	}

	if (oddStart == NULL || evenStart == NULL)
		return;

	evenEnd->next = oddStart;
	oddEnd->next = NULL;
	*head_ref = evenStart;
}

void push(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node* node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

int main() {
	Node* head = NULL;
	push(&head, 11);
	push(&head, 10);
	push(&head, 9);
	push(&head, 6);
	push(&head, 4);
	push(&head, 1);
	push(&head, 0);

	cout << "Original Linked list" << endl;
	printList(head);

	segregateEvenOdd(&head);

	cout << endl << "Modified Linked list " << endl;
	printList(head);

	return 0;
}

