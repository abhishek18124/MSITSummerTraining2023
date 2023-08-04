#include<iostream>
#include<queue>

using namespace std;

int main() {

	char ch;
	queue<char> q;
	int freq[26] = {};

	// time : O(n) ~ n/2 push and n/2 pop

	// space : assume all the i/p characters are unique ~ min(size of the character set or n)

	while (true) {

		cin >> ch;

		freq[ch - 'a']++;
		if (freq[ch - 'a'] == 1) {
			// ch is a non-repeating character
			q.push(ch);
		}

		// find the first non-repeating character for 'ch'

		while (!q.empty() and freq[q.front() - 'a'] > 1) {
			q.pop();
		}

		if (q.empty()) {

			// after reading 'ch' there are no non-repeating characters in the stream

			cout << -1 << " ";

		} else {

			cout << q.front() << " ";

		}

	}

	return 0;
}