// n <= 100

#include<iostream>

using namespace std;

int main() {

	char str[101];

	cout << "Enter a string : ";

	// cin >> str;

	// cin.getline(str, 101); // by default delmiting char = '\n'

	cin.getline(str, 5, '$');

	cout << "You've entered : " << str << endl;

	return 0;
}