// * The Node struct represents each node in the doubly linked list, containing integer data, and pointers to the previous and next nodes.
// * The insertAtBeginning function inserts a new node at the beginning of the list. 
//   It creates a new node with the given data, updates its pointers accordingly, and returns the new head of the list.
// * The printList function traverses the doubly linked list from the given head node and prints the data of each node.

#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert a node at the beginning of a doubly linked list
Node* insertAtBeginning(Node* head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    return newNode;
}

// Function to print the doubly linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 15);

    // Print the doubly linked list
    cout << "Doubly Linked List: ";
    printList(head);

    return 0;
}

