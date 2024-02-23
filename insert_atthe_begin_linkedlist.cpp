// Approach: The new node is always added before the head of the given Linked List. And newly added node becomes the new head of the Linked List. 
// For example, if the given Linked List is 10->15->20->25 and we add an item 5 at the front, then the Linked List becomes 5->10->15->20->25. 
// Let us call the function that adds at the front of the list is push().
// The push() must receive a pointer to the head pointer because the push must change the head pointer to point to the new node 

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

node *insertBegin(node *head,int x)
{
    node *temp=new node(x);
    temp->next=head;
    return temp;
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
    head=insertBegin(head, 20);
    head=insertBegin(head, 30);
    head=insertBegin(head, 40);

    printList(head);

    return 0;
}

