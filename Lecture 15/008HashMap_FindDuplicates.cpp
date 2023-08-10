#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> v = {1, 0, 1, 0, 2, 2, 2, 1, 3, 4, 4, 4};
	int n = v.size();

	// time : O(n)
	// space : O(1) but we are modifying the arr[]

	for (int i = 0; i < n; i++) {

		int x = v[i] % n;
		v[x] += n;

	}

	for (int i = 0; i < v.size(); i++) {

		if (v[i] / n > 1) {
			cout << i << " ";
		}

	}

	cout << endl;

	return 0;
}