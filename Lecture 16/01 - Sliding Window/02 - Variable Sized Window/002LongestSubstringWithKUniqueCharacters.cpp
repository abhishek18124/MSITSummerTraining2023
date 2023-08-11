#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the windw

	int max_len = 0; // to track the length of the longest substring
	// i.e. window that contain k unique characters

	int uniqueCount = 0; // to keep track of no. of unique characters in the window

	unordered_map<char, int> freqMap; // to store a  mapping  between characters
	// present in a window & their frequencies

	// time : O(n)

	// space : O(n) due to freqMap if all the characters in s[] are unique

	while (j < n) {

		// expand the window
		freqMap[s[j]]++;
		if (freqMap[s[j]] == 1) {
			// we are seeing s[j] for the first time
			uniqueCount++;
		}

		// check for the violation of the window property
		if (uniqueCount > k) {
			while (uniqueCount > k) {
				// shrink the window
				freqMap[s[i]]--;
				if (freqMap[s[i]] == 0) {
					uniqueCount--;
				}
				i++;
			}
		}

		// check for the validity of the window, and update the answer
		if (uniqueCount == k) {
			max_len = max(max_len, j - i + 1);
		}

		// continue expansion of the window
		j++;
	}

	cout << max_len << endl;

	return 0;
}