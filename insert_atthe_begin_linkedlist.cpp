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

