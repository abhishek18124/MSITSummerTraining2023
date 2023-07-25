#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str1[100] = "hello";
	char str2[] = "wow";

	cout << "Before copy : " << str1 << endl;

	strcpy(str1, str2);

	cout << "After copy : " << str1 << endl;

	return 0;
}