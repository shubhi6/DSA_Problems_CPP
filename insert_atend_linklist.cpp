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

