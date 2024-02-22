Explanation:

* We define a Node structure to represent each node in the linked list. Each node contains an integer data and a pointer next to the next node.
* The traverseLinkedList function takes the head of the linked list as an argument and traverses the list from the head to the end, 
  printing the data of each node.
* In the main function, we create a linked list by creating nodes and linking them together using the next pointers.
* Finally, we call the traverseLinkedList function with the head of the linked list to print its elements.
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

void printlist(node *head);

int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    printlist(head);
    return 0;
}

void printlist(node *head)
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }
}

