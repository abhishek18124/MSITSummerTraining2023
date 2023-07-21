
// n <= 100

#include<iostream>

using namespace std;

int main() {

	// int arr[] = {10, 20, 30, 40, 50, 60, 70};
	// int n = sizeof(arr) / sizeof(int);

	int arr[100];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int i = 0;
	int j = n - 1;

	// total steps ~ n/2

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