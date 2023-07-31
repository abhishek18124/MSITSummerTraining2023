// constraints : n <= 100

#include<iostream>

using namespace std;

void merge(int* arr, int s, int m, int e) {

	int i = s;
	int j = m + 1;
	int k = s;

	int C[100];

	while (i <= m and j <= e) {

		if (arr[i] < arr[j]) {
			C[k] = arr[i];
			i++;
			k++;
		} else {
			C[k] = arr[j];
			j++;
			k++;
		}

	}

	while (i <= m) {

		C[k] = arr[i];
		i++;
		k++;

	}

	while (j <= e) {

		C[k] = arr[j];
		j++;
		k++;

	}

	for (int l = s; l <= e; l++) {
		arr[l] = C[l];
	}


}

void mergeSort(int* arr, int s, int e) {

	// base case

	if (s == e) {
		// sort the arr[s...s] or arr[e...e]
		return;
	}

	// recursive case

	// sort the arr[s...e]

	// 1. divide the arr[] around the midPoint

	int m = s + (e - s) / 2;

	// 2. recursively, sort the arr[s...m] and arr[m+1...e]

	mergeSort(arr, s, m);
	mergeSort(arr, m + 1, e);

	// 3. merge the two sorted subarrays such that the merged arr[] is sorted

	merge(arr, s, m, e);

}

int main() {

	int arr[] = {60, 50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}