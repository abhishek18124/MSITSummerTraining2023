#include<iostream>
#include<algorithm>

using namespace std;

// time : O(m.logn)

bool search(int mat[][3], int m, int n, int t) {

	for (int i = 0; i < m; i++) {

		if (mat[i][0] > t) {
			// 't' cannot be found in the ith row, skip the ith row
			continue;
		}

		// search for the 't' in the ith row using binary_search

		if (binary_search(mat[i], mat[i + 1], t)) {

			// 't' found in the ith row

			return true;

		}

	}

	// 't' not found
	return false;

}

int main() {

	int mat[][3] = {
		{40, 50, 60},
		{10, 20, 30},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	int t = 80;

	search(mat, m, n, t) ? cout << t << " found!" << endl : cout <<  t << " not found!" << endl;

	return 0;
}