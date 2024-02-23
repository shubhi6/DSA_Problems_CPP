// The new node is always added after the last node of the given Linked List. 
// This can be done using the following 7 steps:

// * Create a new node (say new_node).
// * Put the value in the new node.
// * Make the next pointer of new_node as null.
// * If the list is empty, make new_node as the head.
// * Otherwise, travel to the end of the linked list.
// * Now make the next pointer of last node point to new_node.
// * Change the previous pointer of new_node to the last node of the list.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    
    new_node->prev = last;

   
    last->next = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    cout << "Doubly linked list after insertion: ";
    printList(head);

    return 0;
}

