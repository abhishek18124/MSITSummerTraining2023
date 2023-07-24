// constraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	int csum[101];

	csum[0] = 0;

	// total steps = n

	for (int i = 1; i <= n; i++) {

		csum[i] = csum[i - 1] + arr[i - 1];

	}

	// for (int i = 0; i <= n; i++) {

	// 	cout << csum[i] << " ";

	// }

	// cout << endl

	// total steps ~ n^2.c

	int maxSum = INT_MIN;

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// compute the sum of arr[i...j]

			int sum = csum[j + 1] - csum[i];

			if (sum > maxSum) {
				maxSum = sum;
			}

		}

	}

	cout << maxSum << endl;

	// total steps ~ (n + n^2).c ~ O(n^2)

	// total space ~ O(n)

	return 0;
}









