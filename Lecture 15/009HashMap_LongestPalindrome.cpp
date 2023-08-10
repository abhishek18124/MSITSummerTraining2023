#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main() {

	string str = "aabbccddef";

	unordered_set<int> hasSeen;
	int maxLen = 0;

	for (char ch : str) {
		if (hasSeen.find(ch) != hasSeen.end()) {
			maxLen += 2;
			hasSeen.erase(ch);
		} else {
			hasSeen.insert(ch);
		}
	}

	if (hasSeen.size() > 0) maxLen++;

	cout << maxLen << endl;

	return 0;
}