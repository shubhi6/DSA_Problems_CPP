//............................Clone a linked list with Random Pointer..................

//EXAMPLE:

//Original list :
//Data = 1, Random  = 3
//Data = 2, Random  = 1
//Data = 3, Random  = 5
//Data = 4, Random  = 5
//Data = 5, Random  = 2
//
//Cloned list :
//Data = 1, Random  = 3
//Data = 2, Random  = 1
//Data = 3, Random  = 5
//Data = 4, Random  = 5
//Data = 5, Random  = 2


//.................NAIVE APPROACH..............

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node* arbit;

	Node(int x)
	{
		this->val = x;
		this->next = NULL;
		this->arbit = NULL;
	}
};

Node* cloneLinkedList(Node* head)
{
	unordered_map<Node*, Node*> mp;
	Node *temp, *nhead;

	temp = head;
	nhead = new Node(temp->val);
	mp[temp] = nhead;

	while (temp->next != NULL) {
		nhead->next
			= new Node(temp->next->val);
		temp = temp->next;
		nhead = nhead->next;
		mp[temp] = nhead;
	}
	temp = head;

	while (temp != NULL) {
		mp[temp]->arbit = mp[temp->arbit];
		temp = temp->next;
	}
	return mp[head];
}

void printList(Node* head)
{
	cout << head->val << "("
		<< head->arbit->val << ")";
	head = head->next;
	while (head != NULL) {
		cout << " -> " << head->val << "("
			<< head->arbit->val << ")";
		head = head->next;
	}
	cout << endl;
}

// Driver code
int main()
{

	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next
		= new Node(5);
	head->arbit = head->next->next;
	head->next->arbit = head;
	head->next->next->arbit
		= head->next->next->next->next;
	head->next->next->next->arbit
		= head->next->next;
	head->next->next->next->next->arbit
		= head->next;

	cout << "The original linked list:\n";
	printList(head);


	Node* sol = cloneLinkedList(head);

	cout << "The cloned linked list:\n";
	printList(sol);

	return 0;
}

//.......................EFFICIENT IDEA.................

#include <bits/stdc++.h>
using namespace std;

// Structure of linked list Node
struct Node
{
	int data;
	Node *next,*random;
	Node(int x)
	{
		data = x;
		next = random = NULL;
	}
};

void print(Node *start)
{
	Node *ptr = start;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", Random = "
			<< ptr->random->data << endl;
		ptr = ptr->next;
	}
}

Node* clone(Node *start)
{
	Node* curr = start, *temp;

	while (curr)
	{
		temp = curr->next;

		curr->next = new Node(curr->data);
		curr->next->next = temp;
		curr = temp;
	}

	curr = start;

	while (curr)
	{
		if(curr->next)
			curr->next->random = curr->random ?
								curr->random->next : curr->random;

		curr = curr->next?curr->next->next:curr->next;
	}

	Node* original = start, *copy = start->next;

	temp = copy;

	while (original && copy)
	{
		original->next =
		original->next? original->next->next : original->next;

		copy->next = copy->next?copy->next->next:copy->next;
		original = original->next;
		copy = copy->next;
	}

	return temp;
}

// Driver code
int main()
{
	Node* start = new Node(1);
	start->next = new Node(2);
	start->next->next = new Node(3);
	start->next->next->next = new Node(4);
	start->next->next->next->next = new Node(5);

	start->random = start->next->next;

	start->next->random = start;

	start->next->next->random =
					start->next->next->next->next;
	start->next->next->next->random =
					start->next->next->next->next;

	start->next->next->next->next->random =
									start->next;

	cout << "Original list : \n";
	print(start);

	cout << "\nCloned list : \n";
	Node *cloned_list = clone(start);
	print(cloned_list);

	return 0;
}
