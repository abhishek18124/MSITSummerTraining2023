#include<iostream>
#include<algorithm>

using namespace std;

int helper(int h[], int n) {

	int i = 0;
	int j = n - 1;

	int maxArea = 0;

	while (i < j) {

		int width_ij = j - i;
		int height_ij = min(h[i], h[j]);

		int area_ij = width_ij * height_ij;

		maxArea = max(maxArea, area_ij);

		if (h[i] < h[j]) {

			i++;

		} else {

			j--;

		}

	}

	return maxArea;
}

int main() {

	int h[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int n = sizeof(h) / sizeof(int);

	cout << helper(h, n) << endl;

	return 0;
}