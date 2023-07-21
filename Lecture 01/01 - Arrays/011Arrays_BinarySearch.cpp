#include<iostream>

using namespace std;

int main() {

	int A[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(A) / sizeof(int);

	int t = 100;

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		int m = (s + e) / 2;
		if (A[m] == t) {
			cout << m << " ";
			break;
		} else {
			if (t < A[m]) {
				// reduce the search space from [s, e] to [s, m-1]
				e = m - 1;
			} else { // t > A[m]
				// reduce the search space from [s, e] to [m+1, e]
				s = m + 1;
			}
		}
	}

	if (s > e) {
		// cout << t << " not found!" << endl;
		cout << -1 << endl;
	}

	return 0;
}