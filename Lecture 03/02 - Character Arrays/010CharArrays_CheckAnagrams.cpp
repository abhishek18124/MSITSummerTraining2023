#include<iostream>

using namespace std;

// 1st algo - sort and compare : 2nlogn + n

// 2nd algo - time :  n + n + 26

// space : 26 + 26

bool isAnagram(char* str1, char* str2) {

	int freq1[26];
	memset(freq1, 0, sizeof(freq1));

	for (int i = 0; str1[i] != '\0'; i++) {

		char ch = str1[i];
		int idx = ch - 'a';
		freq1[idx]++;

	}

	for (int i = 0; i < 26; i++) {
		cout << freq1[i] << " ";
	}

	cout << endl;

	int freq2[26];
	memset(freq2, 0, sizeof(freq2));

	for (int i = 0; str2[i] != '\0'; i++) {

		freq2[str2[i] - 'a']++;

	}

	for (int i = 0; i < 26; i++) {
		cout << freq2[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 26; i++) {
		if (freq1[i] != freq2[i]) {
			return false;
		}
	}

	return true;

}

int main() {

	char str1[] = "aabbccc";
	char str2[] = "aabbccc";

	if (isAnagram(str1, str2)) {
		cout << "anagrams" << endl;
	} else {
		cout << "not anagrams" << endl;
	}

	return 0;
}