#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// time : O(n^2)

	int totalWater = 0;

	for (int i = 0; i < n; i++) {

		// compute the water trapped on top of the ith building

		int l_i = h[i]; // max(h[0...i])
		for (int j = i - 1; j >= 0; j--) {
			l_i = max(l_i, h[j]);
		}

		int r_i = h[i]; // max(h[i...n-1])
		for (int j = i + 1; j < n; j++) {
			r_i = max(r_i, h[j]);
		}


		int w_i = min(l_i, r_i) - h[i];
		totalWater += w_i;

	}

	cout << totalWater << endl;

	return 0;
}