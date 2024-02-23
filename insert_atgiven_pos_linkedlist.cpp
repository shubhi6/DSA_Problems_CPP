#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

node *insertAtPosition(node *head, int position, int x)
{
    node *temp = new node(x);
    if(position == 1) {
        temp->next = head;
        return temp;
    }
    node *prev = head;
    for(int i = 1; i < position - 1 && prev != NULL; i++) {
        prev = prev->next;
    }
    if(prev == NULL) {
        cout << "Invalid position\n";
        return head;
    }
    temp->next = prev->next;
    prev->next = temp;
    return head;
}

void printList(node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head=NULL;
    head=insertAtPosition(head, 1, 520);
    head=insertAtPosition(head, 2, 30); 
    head=insertAtPosition(head, 3, 40); 

    printList(head);

    return 0;
}

