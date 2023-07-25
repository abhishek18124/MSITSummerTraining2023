#include<iostream>

using namespace std;

int main() {

	char str1[] = {'a', 'b', 'c', 'd', 'e', '\0'};

	cout << str1 << endl;

	char str2[] = "xyz"; // '\0' is auto. added

	cout << str2 << endl;

	return 0;

}