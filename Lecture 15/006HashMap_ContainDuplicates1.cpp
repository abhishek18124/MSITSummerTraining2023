#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>

using namespace std;

int main() {

	vector<int> v = {1, 3, 2, 1};
	unordered_map<int, int> freqMap;
	bool flag = false; // assume no duplicates

	// // time : O(n)
	// // space : O(n) due to frequency map

	// for (int i = 0; i < v.size(); i++) {

	// 	freqMap[v[i]]++;

	// 	if (freqMap[v[i]] > 1) {
	// 		// we found duplicates
	// 		flag = true;
	// 		break;
	// 	}

	// }

	// for (pair<int, int> p : freqMap) {
	// 	cout << p.first << " " << p.second << endl;
	// }

	// time : O(n)
	// space : O(n)

	unordered_set<int> hashSet;

	for (int i = 0; i < v.size(); i++) {

		if (hashSet.find(v[i]) != hashSet.end()) {
			// you've found duplicate
			flag = true;
			break;
		}

		hashSet.insert(v[i]);

	}

	if (flag == true) {
		cout << "duplilcate found!" << endl;
	} else {
		cout << "duplicate not found!" << endl;
	}




	return 0;
}