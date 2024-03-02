//.............................................Stack with getMin() in O(1).............................................

#include <bits/stdc++.h>
using namespace std;

int mini(int a, int b) { return a > b ? b : a; }

class MinStack {
public:
	stack<pair<int, int>> s;

	void push(int element)
	{
		int new_min = s.empty()
						? element
						: mini(element, s.top().second);

		s.push({ element, new_min });
	}

	int pop()
	{
		int popped;
		if (!s.empty()) {
			popped = s.top().first;
			s.pop();
		}
		else {
			// print a message or throw exception etc
		}
		return popped;
	}

	int minimum()
	{
		int min_elem = s.top().second;
		return min_elem;
	}
};

int main()
{
	MinStack s;
	s.push(-1);
	s.push(10);
	s.push(-4);
	s.push(0);
	cout << s.minimum() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.minimum();
	return 0;
}
