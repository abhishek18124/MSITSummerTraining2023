#include<iostream>
#include<algorithm>

using namespace std;

// currenly, assume 'a' is before 'b'

// return true when swap is not needed

// return false when swap is needed

bool myStringGreaterComparator(string a, string b) {
	// if (a > b) {
	// 	// you don't need a swap for sorting the arr[] in dec order
	// 	return true;
	// }
	// // you need a swap for sorting the arr[] in dec order
	// return false;

	return a > b;
}

bool myStringLesserComparator(string a, string b) {
	// if (a < b) {
	// 	// you don't need a swap for sorting the arr[] in inc order
	// 	return true;
	// }
	// // you need a swap for sorting the arr[] in inc order
	// return false;

	return a < b;
}


int main() {

	string arr[] = {"abc", "ghi", "jkl", "def"};
	int n = 4;

	// sort(arr, arr + n);

	sort(arr, arr + n, myStringLesserComparator);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// sort(arr, arr + n, greater<string>());

	sort(arr, arr + n, myStringGreaterComparator);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}