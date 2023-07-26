#include<iostream>

using namespace std;

int main() {

	int mat[][3] = {
		{10, 20, 30},
		{40, 50, 60},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	for (int j = 0; j < n; j++) {

		if (j % 2 == 0) {

			// jth column is even, print it in top-down fashion

			for (int i = 0; i < m; i++) {

				cout << mat[i][j] << " ";

			}

		} else {


			// jth column is odd, print it in bottom-up fashion

			for (int i = m - 1; i >= 0; i--) {

				cout << mat[i][j] << " ";

			}

		}

	}

	return 0;
}