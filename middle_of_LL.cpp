//.............METHOD 1.......

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class NodeOperation {
public:
    void pushNode(Node** head_ref, int data_val)
    {
        Node* new_node = new Node();
        new_node->data = data_val;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }

    void printNode(Node* head)
    {
        while (head != NULL) {
            cout << head->data << "->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }

    int getLen(Node* head)
    {
        int len = 0;
        Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void printMiddle(Node* head)
    {
        if (head) {
            int len = getLen(head);
            Node* temp = head;
            int midIdx = len / 2;
            while (midIdx--) {
                temp = temp->next;
            }
            cout << "The middle element is [" << temp->data << "]" << endl;
        }
    }
};

int main()
{
    Node* head = NULL;
    NodeOperation* temp = new NodeOperation();
    for (int i = 5; i > 0; i--) {
        temp->pushNode(&head, i);
        temp->printNode(head);
        temp->printMiddle(head);
    }
    return 0;
}


//........METHOD 2...........

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class NodeOperation {
public:
    void pushNode(Node** head_ref, int data_val) {
        Node* new_node = new Node();
        new_node->data = data_val;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }

    void printNode(Node* head) {
        while (head != NULL) {
            cout << head->data << "->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }

    void printMiddle(Node* head) {
        Node* slow_ptr = head;
        Node* fast_ptr = head;

        if (head != NULL) {
            while (fast_ptr != NULL && fast_ptr->next != NULL) {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
            cout << "The middle element is [" << slow_ptr->data << "]" << endl;
        }
    }
};

int main() {
    Node* head = NULL;
    NodeOperation* temp = new NodeOperation();
    for (int i = 5; i > 0; i--) {
        temp->pushNode(&head, i);
        temp->printNode(head);
        temp->printMiddle(head);
    }
    return 0;
}

