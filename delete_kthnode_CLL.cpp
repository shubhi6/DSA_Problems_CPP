#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* deleteKthNode(Node* head, int k) {
    if (!head)
        return NULL;
    
    if (k == 1) {
        if (head->next == head) {
            delete head;
            return NULL;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = head->next;
            Node* nextNode = head->next;
            delete head;
            return nextNode;
        }
    }
    
    Node* temp = head;
    for (int i = 0; i < k - 2; ++i)
        temp = temp->next;
    
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return head;
}

void printList(Node* head) {
    if (!head)
        return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Node* head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    cout << "Before deletion: ";
    printList(head);

    int k = 3;
    head = deleteKthNode(head, k);

    cout << "\nAfter deletion of " << k << "th node: ";
    printList(head);

    return 0;
}

