/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>

using namespace std;

void f(char* inp, int i, int n) {

	// base case

	if (i == n) { // or inp[i] == '\0'

		cout << inp  << endl;
		return;

	}

	// recursive case

	// you've to take decisions for the remaining positions i to n-1

	// take a decision for the ith position

	for (int j = i; j <= n - 1; j++) {

		// we've decided to assign the char. at the jth index to the ith position

		swap(inp[i], inp[j]);

		// ask your friend to take decisions for the reamining positions i+1 to n-1

		f(inp, i + 1, n);

		swap(inp[i], inp[j]); // backtracking or undo

	}

}

int main() {

	char inp[] = "abc";
	int n = strlen(inp);

	f(inp, 0, n);

	return 0;
}
