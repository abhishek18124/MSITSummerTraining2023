#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	string str = "abcde";
	int n = str.size();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			// generate the subString that starts at the ith index and ends at the jth index
			string subString = str.substr(i, j - i + 1);
			cout << subString << endl;

		}

		cout << endl;
	}

	cout << endl;

	return 0;
}