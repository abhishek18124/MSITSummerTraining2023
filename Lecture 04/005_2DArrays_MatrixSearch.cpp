#include<iostream>

using namespace std;

// time : O(m.n)

bool search(int mat[][3], int m, int n, int t) {

	for (int i = 0; i < m; i++) {

		// search for the 't' in the ith row

		for (int j = 0; j < n; j++) {

			if (mat[i][j] == t) {

				return true;

			}

		}

	}

	// t not found
	return false;

}

int main() {

	int mat[][3]  = {
		{50, 80, 20},
		{90, 10, 70},
		{60, 30, 40}
	};

	int m = 3;
	int n = 3;

	int t = 100;

	search(mat, m, n, t) ? cout << t << " found !" << endl : cout << t << " not found!" << endl;

	// if (search(mat, m, n, t)) {
	// 	cout << t << " found!" << endl;
	// } else {
	// 	cout << t << " not found!" << endl;
	// }

	return 0;
}