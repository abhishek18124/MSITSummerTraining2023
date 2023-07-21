#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int k = 3;

	// // approach 1 - time : O(n.k)

	// for (int j = 0; j < k; j++) {

	// 	int temp  = arr[n - 1];

	// 	for (int i = n - 1; i >= 1; i--) {
	// 		arr[i] = arr[i - 1];
	// 	}

	// 	arr[0] = temp;

	// }

	// approach - 2 time : O(n)

	// 1. reverse the entire array

	int i = 0;
	int j = n - 1;

	while (i < j) {

		swap(arr[i], arr[j]);
		i++;
		j--;

	}

	// 2. reverse the first-k elements

	i = 0;
	j = k - 1;

	while (i < j) {

		swap(arr[i], arr[j]);
		i++;
		j--;

	}

	// 3. reverse the last n-k elements

	i = k;
	j = n - 1;

	while (i < j) {

		swap(arr[i], arr[j]);
		i++;
		j--;

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}