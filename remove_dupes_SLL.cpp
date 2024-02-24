// Write a function that takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list. The list should only be traversed once. 
// For example if the linked list is 11->11->11->21->43->43->60 then removeDuplicates() should convert the list to 11->21->43->60. 

// Algorithm: Traverse the list from the head (or start) node. While traversing, compare each node with its next node. 
// If the data of the next node is the same as the current node then delete the next node. Before we delete a node, we need to store the next pointer of the node 

// Implementation: Functions other than removeDuplicates() are just to create a linked list and test removeDuplicates(). 

// EXAMPLE:

// Linked list before duplicate removal  11 11 11 13 13 20
// Linked list after duplicate removal  11 13 20

// Linked list before duplicate removal  21 50 50 68 90 99
// Linked list after duplicate removal  21 50 68 90 99

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void removeDuplicates(Node* head) {
    Node* current = head;
    Node* next_next;

    if (current == NULL)
        return;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);

    cout << "Linked list before duplicate removal ";
    printList(head);

    removeDuplicates(head);

    cout << "\nLinked list after duplicate removal ";
    printList(head);

    return 0;
}

