// n <= 50 and m <= 50

#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str1[101] = "abc";
	char str2[] = "def";

	cout << "Before concat : " << str1 << endl;

	strcat(str1, str2);

	cout << "After concat : " << str1 << endl;

	return 0;
}