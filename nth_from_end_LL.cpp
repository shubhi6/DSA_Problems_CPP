// Given a Linked List and a number N, write a function that returns the value at the Nth node from the end of the Linked List.
	
// Examples:

// Input: 1 -> 2 -> 3 -> 4, N = 3
// Output: 2

// Input: 35 -> 15 -> 4 -> 20, N = 4
// Output: 35   

//............NAIVE APPROACH...........

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void printNthFromLast(struct Node* head, int N) {
    int len = 0, i;
    struct Node* temp = head;

    while (temp != NULL) {
        temp = temp->next;
        len++;
    }

    if (len < N)
        return;

    temp = head;

    for (i = 1; i < len - N + 1; i++)
        temp = temp->next;

    cout << temp->data;

    return;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
	
    printNthFromLast(head, 4);
    return 0;
}



//.............EFFICIENT APPROACH............


#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

struct llist {
    node* head;
    llist() { head = NULL; }

    void insertAtBegin(int val) {
        node* newNode = new node(val);
        newNode->next = head;
        head = newNode;
    }

    void nthFromEnd(int n) {
        node* main_ptr = head;
        node* ref_ptr = head;
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        for (int i = 1; i < n; i++) {
            ref_ptr = ref_ptr->next;
            if (ref_ptr == NULL) {
                cout << n << " is greater than no. of nodes in the list" << endl;
                return;
            }
        }
        while (ref_ptr != NULL && ref_ptr->next != NULL) {
            ref_ptr = ref_ptr->next;
            main_ptr = main_ptr->next;
        }
        cout << "Node no. " << n << " from end is: " << main_ptr->data << endl;
    }

    void displaylist() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    llist ll;
    ll.insertAtBegin(20);
    ll.insertAtBegin(4);
    ll.insertAtBegin(15);
    ll.insertAtBegin(35);
    ll.displaylist();
    ll.nthFromEnd(4);
    return 0;
}

