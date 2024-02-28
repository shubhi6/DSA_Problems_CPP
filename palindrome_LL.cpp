//...................Check if a Singly Linked List is Palindrome by Reversing the Linked List:................
//The idea is to first reverse the second half part of the linked list and then check whether the list is palindrome or not.

//Follow the steps below to solve the problem:

//* Get the middle of the linked list. 
//* Reverse the second half of the linked list. 
//* Check if the first half and second half are identical. 
//* Construct the original linked list by reversing the second half again and attaching it back to
// the first half

//Examples:

//Input: R->A->D->A->R->NULL
//Output: Yes

//Input: C->O->D->E->NULL
//Output: No


#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node* next;
};

void reverse(struct Node**);
bool compareLists(struct Node*, struct Node*);
bool isPalindrome(struct Node* head) {
    struct Node *slow_ptr = head, *fast_ptr = head;
    struct Node *second_half, *prev_of_slow_ptr = head;
    bool res = true;

    if (head != NULL && head->next != NULL) {
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        if (fast_ptr != NULL) {
            slow_ptr = slow_ptr->next;
        }

        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL;
        reverse(&second_half);
        res = compareLists(head, second_half);
        reverse(&second_half);

        if (fast_ptr != NULL) {
            prev_of_slow_ptr->next = head;
            prev_of_slow_ptr = head;
            head = head->next;
        }
        prev_of_slow_ptr->next = second_half;
    }
    return res;
}

void reverse(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

bool compareLists(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->data != temp2->data) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return (temp1 == NULL && temp2 == NULL);
}

void push(struct Node** head_ref, char new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* ptr) {
    while (ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << "\n";
}

int main() {
    struct Node* head = NULL;
    char str[] = "abacaba";
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        push(&head, str[i]);
    }
    isPalindrome(head) ? cout << "Is Palindrome" << "\n\n" : cout << "Not Palindrome" << "\n\n";
    return 0;
}

