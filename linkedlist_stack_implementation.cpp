#include <iostream>
#include <cstdlib>

class Node {
public:
	int data;
	Node* link;

	Node(int n) {
		this->data = n;
		this->link = NULL;
	}
};

class Stack {
	Node* top;

public:
	Stack() { top = NULL; }

	void push(int data) {
		Node* temp = new Node(data);
		if (!temp) {
			std::cout << "\nStack Overflow";
			exit(1);
		}
		temp->data = data;
		temp->link = top;
		top = temp;
	}

	bool isEmpty() {
		return top == NULL;
	}

	int peek() {
		if (!isEmpty())
			return top->data;
		else
			exit(1);
	}

	void pop() {
		Node* temp;
		if (top == NULL) {
			std::cout << "\nStack Underflow" << std::endl;
			exit(1);
		}
		else {
			temp = top;
			top = top->link;
			free(temp);
		}
	}

	void display() {
		Node* temp;
		if (top == NULL) {
			std::cout << "\nStack Underflow";
			exit(1);
		}
		else {
			temp = top;
			while (temp != NULL) {
				std::cout << temp->data;
				temp = temp->link;
				if (temp != NULL)
					std::cout << " -> ";
			}
		}
	}
};

int main() {
	Stack s;
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);
	s.display();
	std::cout << "\nTop element is " << s.peek() << std::endl;
	s.pop();
	s.pop();
	s.display();
	std::cout << "\nTop element is " << s.peek() << std::endl;
	return 0;
}

