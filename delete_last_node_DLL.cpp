// Write a function to delete the last node in a doubly-linked list. 

#include <bits/stdc++.h> 
using namespace std; 

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* deleteLastNode(Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
        delete temp;
    } else {
        delete head;
        return NULL;
    }
    return head;
}

int main() { 
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;

    cout << "Original list: ";
    printList(head);

    head = deleteLastNode(head);
    cout << "List after deleting last node: ";
    printList(head);

    return 0;
}


