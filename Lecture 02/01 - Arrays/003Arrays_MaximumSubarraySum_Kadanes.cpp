// constraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = { -3, 2, -1, 4, -5};
	// int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	// // time : O(n) space : O(n)

	// int x[100];


	// x[0] = arr[0];
	// int maxSum = x[0];

	// for (int i = 1; i <= n - 1; i++) {
	// 	x[i] = max(x[i - 1] + arr[i], arr[i]);
	// 	// if(x[i] > maxSum) {
	// 	// 	maxSum = x[i];
	// 	// }
	// 	maxSum = max(maxSum, x[i]);
	// }

	// cout << maxSum << endl;

	// for (int i = 0; i <= n - 1; i++) {
	// 	cout << x[i] << " ";
	// }

	// cout << endl;


	// time : O(n) space : O(1)

	int x = arr[0];
	int maxSum = x;

	for (int i = 1; i <= n - 1; i++) {
		x = max(x + arr[i], arr[i]);
		maxSum = max(maxSum, x);
	}

	cout << maxSum << endl;


	return 0;
}