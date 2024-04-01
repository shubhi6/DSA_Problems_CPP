// Detect loop in a linked list using Floyd’s Cycle-Finding Algorithm:
// This algorithm is used to find a loop in a linked list. It uses two pointers one moving twice as fast as the other one.
// The faster one is called the faster pointer and the other one is called the slow pointer.

// Follow the steps below to solve the problem:

// * Traverse linked list using two pointers.
// * Move one pointer(slow_p) by one and another pointer(fast_p) by two.
// * If these pointers meet at the same node then there is a loop. If pointers do not meet then the linked list doesn’t have a loop.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int detectLoop(Node* list) {
	Node *slow_p = list, *fast_p = list;
	while (slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p) {
			return 1;
		}
	}
	return 0;
}

int main() {
	Node* head = NULL;
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);
	head->next->next->next->next = head;
	if (detectLoop(head))
		cout << "Loop Found";
	else
		cout << "No Loop";
	return 0;
}

