#include<iostream>
#include<cstring>

using namespace std;

int myStringCompare(char* str1, char* str2) {

	int i = 0;
	int j = 0;


	while (str1[i] != '\0' and str2[j] != '\0') {

		if (str1[i] < str2[j]) {
			// str1 < str2
			return -1;
		}

		if (str1[i] > str2[j]) {
			// str1 > str2
			return 1;
		}

		i++;
		j++;

	}

	if (str1[i] == '\0' and str2[j] != '\0') {
		// len(str1) < len(str2) therefore str1 < str2
		return -1;
	}

	if (str1[i] != '\0' and str2[j] == '\0') {
		// len(str1) > len(str2) therefore str1 > str2
		return 1;
	}

	// all char. of str1 match with str2 and lengths also match therefore they are equal

	return 0;

}

int main() {

	char str1[] = "xyx";
	char str2[] = "xyz";


	// int ans = myStringCompare(str1, str2);

	int ans = strcmp(str1, str2);

	if (ans == 0) {
		cout << "equal" << endl;
	} else if (ans > 0) {
		cout << "str1 > str2" << endl;
	} else {
		cout << "str1 < str2" << endl;
	}

	return 0;
}