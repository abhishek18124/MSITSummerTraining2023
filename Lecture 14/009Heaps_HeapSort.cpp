/*

	Given an array of n integers, sort the array using heap sort algorithm.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& v, int n, int i) {

	// this function fixes the heap prop. at the ith index

	int maxIdx = i;

	int leftIdx = 2 * i + 1;
	if (leftIdx < n and v[leftIdx] > v[maxIdx]) {
		maxIdx = leftIdx;
	}

	int rightIdx = 2 * i + 2;
	if (rightIdx < n and v[rightIdx] > v[maxIdx]) {
		maxIdx = rightIdx;
	}

	if (maxIdx != i) {
		// there is a violation of the maxHeap prop. at the ith index
		swap(v[i], v[maxIdx]);
		heapify(v, n, maxIdx);
	}

}


int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// 1. transform v[] into a maxHeap : O(n)

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	int heapsize = v.size();

	// 2. tranform maxHeap into a sorted array ?

	// (n-1).logn ~ nlogn

	while (heapsize > 1) {

		swap(v[0], v[heapsize - 1]);
		heapsize--;
		heapify(v, heapsize, 0);

	}

	// total time : n + nlogn ~ O(nlogn)

	// totall space : O(logn) due to function call stack if we don't consider modification of v[]
	// totall space : O(n + logn) if we consider modifying v[]

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
