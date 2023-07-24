#include<iostream>
#include<climits>

using namespace std;

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	// time : O(n^3)

	int maxSum = INT_MIN;

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// compute the sum of arr[i...j]

			int sum = 0;

			for (int k = i; k <= j; k++) {

				sum += arr[k];

			}

			if (sum > maxSum) {
				maxSum = sum;
			}

		}

	}

	cout << maxSum << endl;

	return 0;
}