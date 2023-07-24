#include<iostream>

using namespace std;

int helper(int h[], int n) {
	int i = 0;
	int j = n - 1;

	int totalWater = 0;

	int l = INT_MIN; // or 0 or h[0] // max[0..i]
	int r = INT_MIN; // or 0 or h[n-1] // max[j...n-1]

	while (i <= j) {

		l = max(l, h[i]);
		r = max(r, h[j]);

		if (l < r) {

			int w_i = l - h[i];
			totalWater += w_i;
			i++;

		} else {

			int w_j = r - h[j];
			totalWater += w_j;
			j--;

		}

	}

	return totalWater;
}

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// time : O(n) space : O(1)

	cout << helper(h, n) << endl;

	return 0;
}