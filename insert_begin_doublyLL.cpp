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

