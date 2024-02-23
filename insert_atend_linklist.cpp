// * The new node is always added after the last node of the given Linked List. 
//   For example if the given Linked List is 5->10->15->20->25 and we add an item 30 at the end, then the Linked List becomes 5->10->15->20->25->30. 
// * Since a Linked List is typically represented by the head of it, we have to traverse the list till the end and then change the next to last node to a new node.

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

node *insertEnd(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    return temp;
    node *curr=head;
    while(curr->next!=NULL)
    curr=curr->next;
    curr->next=temp;
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
    head=insertEnd(head, 20);
    head=insertEnd(head, 30);
    head=insertEnd(head, 40);

    printList(head);

    return 0;
}

