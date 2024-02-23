//The idea is simple, we print current node and recur for remaining list. 

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

void printlistrec(node *head);

int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    printlistrec(head);
    return 0;
}

void printlistrec(node *head)
{
    if(head != NULL)
    {
        cout << head->data << " ";
        printlistrec(head->next);
    }
}

