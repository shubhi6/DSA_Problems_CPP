#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

Node* removeLastNode(Node* head) {
	if (head == NULL)
		return NULL;

	if (head->next == NULL) {
		delete head;
		return NULL;
	}

	Node* second_last = head;
	while (second_last->next->next != NULL)
		second_last = second_last->next;

	delete (second_last->next);
	second_last->next = NULL;

	return head;
}

void push(Node** head_ref, int new_data) {
	Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main() {
	Node* head = NULL;

	push(&head, 12);
	push(&head, 29);
	push(&head, 11);
	push(&head, 23);
	push(&head, 8);

	head = removeLastNode(head);
	for (Node* temp = head; temp != NULL; temp = temp->next)
		cout << temp->data << " ";

	return 0;
}

