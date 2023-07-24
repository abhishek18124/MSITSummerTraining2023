// contraints : m <= 10, n <= 10

#include<iostream>

using namespace std;

int main() {

	int A[] = {10, 30, 50, 70};
	int B[] = {20, 40, 60};

	int m = sizeof(A) / sizeof(int);
	int n = sizeof(B) / sizeof(int);

	int C[20];

	int i = 0; // to iterate over A[]
	int j = 0; // to iterate over B[]
	int k = 0; // to iterate over C[]

	// time : O(m+n)

	while (i < m and j < n) {

		if (A[i] < B[j]) {
			C[k] = A[i];
			i++;
			k++;
		} else {
			C[k] = B[j];
			j++;
			k++;
		}

	}

	while (i < m) {

		C[k] = A[i];
		i++;
		k++;

	}

	while (j < n) {

		C[k] = B[j];
		j++;
		k++;

	}

	for (int l = 0; l < m + n; l++) {
		cout << C[l] << " ";
	}

	cout << endl;



	return 0;
}

