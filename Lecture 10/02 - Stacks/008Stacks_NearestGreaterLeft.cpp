#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void f(int* A, int n) {

	stack<int> s;

	vector<int> v;

	for (int i = 0; i <= n - 1; i++) {

		// find the nearest greater element to the left of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// cout << -1 << " ";
			v.push_back(-1);
		} else {
			// cout << s.top() << " ";
			v.push_back(s.top());
		}

		s.push(A[i]);

	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

}



int main() {

	int A[] = {5, 2, 0, 4, 1, 3, 6};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}