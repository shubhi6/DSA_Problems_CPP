// Given a linked list, write a function to reverse every k nodes (where k is an input to the function). 

// Example: 

// Input: 1->2->3->4->5->6->7->8->NULL, K = 3 
// Output: 3->2->1->6->5->4->8->7->NULL 
// Input: 1->2->3->4->5->6->7->8->NULL, K = 5 
// Output: 5->4->3->2->1->8->7->6->NULL 

//................RECURSIVE SOLUTION..........

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* reverse(Node* head, int k) {
	if (!head)
		return NULL;
	Node* current = head;
	Node* next = NULL;
	Node* prev = NULL;
	int count = 0;

	while (current != NULL && count < k) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	if (next != NULL)
		head->next = reverse(next, k);

	return prev;
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

	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printList(head);
	head = reverse(head, 3);

	cout << "\n";
	printList(head);

	return (0);
}


//...............ITERATIVE SOLUTION..............

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* reverse(Node* head, int k) {
    if (!head || k == 1)
        return head;

    Node* dummy = new Node();
    dummy->data = -1;
    dummy->next = head;

    Node *prev = dummy, *curr = dummy, *next = dummy;

    int count = 0;
    while (curr) {
        curr = curr->next;
        count++;
    }

    while (next) {
        curr = prev->next;
        next = curr->next;
        int toLoop = count > k ? k : count - 1;
        for (int i = 1; i < toLoop; i++) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        count -= k;
    }
    return dummy->next;
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

    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printList(head);
    head = reverse(head, 3);

    cout << "\n";
    printList(head);

    return (0);
}

