#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> s) {

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

}

void insertAtBottom(stack<int>& s, int val) {

	// base case

	if (s.empty()) {
		s.push(val);
		return;
	}

	// recursive case

	int x = s.top();
	s.pop();

	insertAtBottom(s, val);

	s.push(x);

}


// time : O(n^2)
// spacce : O(n)

void reverse(stack<int>& s) {

	// base case

	if (s.empty()) {
		return;
	}

	// recursive case

	int x = s.top();
	s.pop();

	reverse(s);

	insertAtBottom(s, x);

}

int main() {

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	print(s);

	reverse(s);

	print(s);

	return 0;
}