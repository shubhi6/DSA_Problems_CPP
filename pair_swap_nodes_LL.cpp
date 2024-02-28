//.....................Pairwise Swap Nodes of linked list..............
// EXAMPLE:
//Given a singly linked list, write a function to swap elements pairwise.

//Input : 1->2->3->4->5->6->NULL
//Output : 2->1->4->3->6->5->NULL

//Input : 1->2->3->4->5->NULL
//Output : 2->1->4->3->5->NULL

//Input : 1->NULL
//Output : 1->NULL

//...................Method 1 :  Swapping Data................

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

void pairwiseSwap(Node *head){
    Node *curr=head;
    while(curr!=NULL&&curr->next!=NULL){
        swap(curr->data,curr->next->data);
        curr=curr->next->next;
    }
}

int main()
{
	Node *head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(3);
	head->next->next->next=new Node(4);
	head->next->next->next->next=new Node(5);
	printlist(head);
	pairwiseSwap(head);
	printlist(head);
	return 0;
}

//..................Method 2: Changing Pointers/References................

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

Node *pairwiseSwap(Node *head){
    if(head==NULL||head->next==NULL)
        return head;
    Node *curr=head->next->next;
    Node *prev=head;
    head=head->next;
    head->next=prev;
    while(curr!=NULL&&curr->next!=NULL){
        prev->next=curr->next;
        prev=curr;
        Node *next=curr->next->next;
        curr->next->next=curr;
        curr=next;
    }
    prev->next=curr;
    return head;
}

int main()
{
	Node *head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(3);
	head->next->next->next=new Node(4);
	head->next->next->next->next=new Node(5);
	printlist(head);
	head=pairwiseSwap(head);
	printlist(head);
	return 0;
}
