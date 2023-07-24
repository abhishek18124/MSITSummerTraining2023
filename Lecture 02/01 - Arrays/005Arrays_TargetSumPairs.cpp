#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr) / sizeof(int);
	int t = 60;

	int count = 0;

	// // time : O(n^2)

	// for (int i = 0; i <= n - 2; i++) {

	// 	for (int j = i + 1; j <= n - 1; j++) {

	// 		int sum = arr[i] + arr[j];

	// 		if (sum == t) {
	// 			count++;
	// 		}

	// 	}

	// }

	// time : O(n)

	// worst case : n steps
	// best case : n/2 steps

	int i = 0;
	int j = n - 1;

	while (i < j) {

		int sum = arr[i] + arr[j];

		if (sum > t) {
			j--;
		} else if (sum < t) {
			i++;
		} else {
			count++;
			i++;
			j--;
		}

	}

	cout << count << endl;

	return 0;
}