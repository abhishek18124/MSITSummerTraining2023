#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// void f(int* A, int n) {

// 	stack<pair<int, int>> s; // pair<int, int> : <value, index>

// 	vector<int> v;

// 	for (int i = 0; i <= n - 1; i++) {

// 		// compute the span for the ith day

// 		// find the index of the nearest greater element to the left of A[i]

// 		while (!s.empty() and s.top().first <= A[i]) {
// 			s.pop();
// 		}

// 		int j;

// 		if (s.empty()) {
// 			// cout << -1 << " ";
// 			j = -1;
// 		} else {
// 			// cout << s.top() << " ";
// 			j = s.top().second;
// 		}

// 		// int span_ith_day = i-j;

// 		v.push_back(i - j);

// 		s.push({A[i], i}); // make_pair(A[i], i)

// 	}

// 	for (int i = 0; i < v.size(); i++) {
// 		cout << v[i] << " ";
// 	}

// 	cout << endl;

// }

void f(int* A, int n) {

	stack<int> s; // index

	vector<int> v;

	for (int i = 0; i <= n - 1; i++) {

		// compute the span for the ith day

		// find the index of the nearest greater element to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			// cout << -1 << " ";
			j = -1;
		} else {
			// cout << s.top() << " ";
			j = s.top();
		}

		// int span_ith_day = i-j;

		v.push_back(i - j);

		s.push(i);

	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

}


int main() {

	int A[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}