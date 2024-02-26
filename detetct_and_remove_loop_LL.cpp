// Method using Floyd’s Cycle detection algorithm :

//* This method is also dependent on Floyd’s Cycle detection algorithm.
//* Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
//* Count the number of nodes in the loop. Let the count be k.
//* Fix one pointer to the head and another to a kth node from the head.
//* Move both pointers at the same pace, they will meet at the loop starting node.
//* Get a pointer to the last node of the loop and make the next of it NULL.

// EXAMPLE:

// INPUT : 15 20 50 4 10

// OUTPUT: Linked List after removing loop 
//          50 20 15 4 10 

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void removeLoop(struct Node*, struct Node*);

int detectAndRemoveLoop(struct Node* list) {
	struct Node *slow_p = list, *fast_p = list;
	while (slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p) {
			removeLoop(slow_p, list);
			return 1;
		}
	}
	return 0;
}

void removeLoop(struct Node* loop_node, struct Node* head) {
	struct Node* ptr1 = loop_node;
	struct Node* ptr2 = loop_node;
	unsigned int k = 1, i;
	while (ptr1->next != ptr2) {
		ptr1 = ptr1->next;
		k++;
	}
	ptr1 = head;
	ptr2 = head;
	for (i = 0; i < k; i++)
		ptr2 = ptr2->next;
	while (ptr2 != ptr1) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	while (ptr2->next != ptr1)
		ptr2 = ptr2->next;
	ptr2->next = NULL;
}

void printList(struct Node* node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

struct Node* newNode(int key) {
	struct Node* temp = new Node();
	temp->data = key;
	temp->next = NULL;
	return temp;
}

int main() {
	struct Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);
	head->next->next->next->next->next = head->next->next;
	detectAndRemoveLoop(head);
	cout << "Linked List after removing loop \n";
	printList(head);
	return 0;
}

