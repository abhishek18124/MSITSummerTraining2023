#include<iostream>

using namespace std;

// total steps in the worst case - n/2 ~ O(n)
// space : O(1)

bool isPalindrome(char str[]) {

	int i = 0;
	int j = strlen(str) - 1;

	while (i < j) {

		if (str[i] != str[j]) {
			return false;
		}

		i++;
		j--;

	}

	return true;

}

int main() {

	char str[] = "abcdba";

	isPalindrome(str) ? cout << "palindrome" << endl :
	                         cout << "not a palindrome" << endl;

	return 0;
}