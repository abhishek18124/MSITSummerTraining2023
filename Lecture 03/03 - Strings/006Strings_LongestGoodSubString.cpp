#include<iostream>
#include<algorithm>

using namespace std;

bool isGoodString(string str) {

	for (int i = 0; i < str.size(); i++) {

		char ch = str[i];

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is a consonant
			return false;
		}

	}

	return true;

}

int main() {

	string str = "cbaeicdeiou";
	int n = str.size();

	int maxLen = 0;

	// time : O(n^3)

	// for (int i = 0; i < n; i++) {
	// 	for (int j = i; j < n; j++) {
	// 		string subString = str.substr(i, j - i + 1);
	// 		if (isGoodString(subString)) {
	// 			maxLen = max(maxLen, j - i + 1);
	// 		}

	// 	}
	// }

	int count = 0;

	// for (int i = 0; i < n; i++) {

	// 	char ch = str[i];

	// 	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
	// 		count++;
	// 		maxLen = max(maxLen, count);
	// 	} else {
	// 		count = 0;
	// 	}

	// }

	for (char ch : str) {

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			count++;
			maxLen = max(maxLen, count);
		} else {
			count = 0;
		}

	}

	cout << maxLen << endl;

	return 0;
}