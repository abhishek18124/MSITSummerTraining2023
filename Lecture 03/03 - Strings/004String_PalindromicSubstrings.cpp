#include<iostream>

using namespace std;

int countPalindromicSubstrings(string s) {


	int n = s.size();
	int count = 0; // to track the no. of palindromic substrings in the given string

	// 1. count all the odd length palindromic subStrings

	// for a string of length 'n' there are 'n' centers for odd-length palindromic substring

	for (int i = 0; i < n; i++) {

		// count the no. of odd-length palindromic substrings around the ith character

		int j = 0;

		while (i - j >= 0 and i + j <= n - 1 and s[i - j] == s[i + j]) {
			count++;
			j++;
		}

	}

	// 2. count all the even length palindromic subStrings

	for (double i = 0.5; i < n; i++) {

		// count the no. of even-length palindromic substrings around the ith even-center

		double j = 0.5;

		while (i - j >= 0 and i + j <= n - 1 and s[int(i - j)] == s[int(i + j)]) {
			count++;
			j++;
		}

	}


	return count;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}