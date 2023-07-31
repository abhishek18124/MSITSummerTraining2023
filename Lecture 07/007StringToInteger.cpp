#include<iostream>

using namespace std;

int stringToInteger(string s, int n) {

	// base case

	if (s == "") { // n == 0 or s.empty()
		return 0;
	}

	// recursive case

	string subString = s.substr(0, n - 1);

	// ask your friend to convert the subString into an integer

	int A = stringToInteger(subString, n - 1);

	int lastDigit = s[n - 1] - '0';

	return A * 10 + lastDigit;

}

int main() {

	string s = "1234";
	int n = s.size();

	int x = stringToInteger(s, n);

	cout << x << endl;

	cout << x + 1 << endl;

	return 0;
}