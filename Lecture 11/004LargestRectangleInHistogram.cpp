#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int f(int* h, int n) {

	stack<pair<int, int>> s; // <value, index>

	vector<int> v1;

	for (int i = n - 1; i >= 0; i--) {

		// find the index of the nearest smaller element to the right of h[i]

		while (!s.empty() and s.top().first >= h[i]) {
			s.pop();
		}

		if (s.empty()) {

			// h[i] doesn't have nearest smaller element to its right

			v1.push_back(n);

		} else {

			v1.push_back(s.top().second);

		}

		s.push({h[i], i}); // s.push(make_pair(h[i], i))

	}

	reverse(v1.begin(), v1.end());

	while (!s.empty()) {
		s.pop();
	}

	vector<int> v2;

	for (int i = 0; i <= n - 1; i++) {

		// find the index of the nearest smaller element to the left of h[i]

		while (!s.empty() and s.top().first >= h[i]) {
			s.pop();
		}

		if (s.empty()) {

			// h[i] doesn't have nearest smaller element to its left

			v2.push_back(-1);

		} else {

			v2.push_back(s.top().second);

		}

		s.push({h[i], i}); // s.push(make_pair(h[i], i))

	}

	int maxArea = 0;

	for (int i = 0; i < n; i++) {

		// find the area of the largest rectangle with the height as h[i]

		int w_best = (v1[i] - v2[i]) - 1;
		int area = h[i] * w_best;
		maxArea = max(maxArea, area);

	}

	return maxArea;


}

int main() {

	int h[] = {2, 1, 5, 6, 2, 3};
	int n = sizeof(h) / sizeof(int);

	cout << f(h, n) << endl;

	return 0;
}