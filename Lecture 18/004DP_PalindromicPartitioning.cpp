#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string str) {
	int i = 0;
	int j = str.size() - 1;
	while (i < j) {
		if (str[i] != str[j]) return false;
		i++;
		j--;
	}
	return true;
}

int countPalindromicPartitioning(string str, int n, int i, vector<string>& v) {

	// base case

	if (i == n) {
		for (string cut : v) cout << cut << " ";
		cout << endl;
		return 1;
	}

	// recursive case

	// count the number of palindromic partitioning of str[i...n-1]

	int count = 0;

	for (int j = i; j <= n - 1; j++) {
		string subString = str.substr(i, j - i + 1);
		if (isPalindrome(subString)) {
			v.push_back(subString);
			// you can make a cut at the jth index
			count += countPalindromicPartitioning(str, n, j + 1, v);
			v.pop_back(); // backtracking
		}
	}

	return count;

}

int countPalindromicPartitioningBottomUp(string str, int n) {

	vector<int> dp(n + 1);

	dp[n] = 1; // since at the nth index of dp[], we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		// count the number of palindromic partitioning of str[i...n-1]

		int count = 0;

		for (int j = i; j <= n - 1; j++) {
			string subString = str.substr(i, j - i + 1);
			if (isPalindrome(subString)) {
				// you can make a cut at the jth index
				count += dp[j + 1];
			}
		}

		dp[i] = count;

	}

	return dp[0];

}

int main() {

	string str = "abab";

	vector<string> v;

	cout << countPalindromicPartitioning(str, str.size(), 0, v) << endl;

	cout << countPalindromicPartitioningBottomUp(str, str.size()) << endl;

	return 0;
}