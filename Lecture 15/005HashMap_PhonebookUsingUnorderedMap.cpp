/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phoneMap;

	phoneMap["Shubham"].push_back("1234");
	phoneMap["Shubham"].push_back("5678");
	phoneMap["Shubham"].push_back("9876");

	phoneMap["Yash"].push_back("0000");
	phoneMap["Kunal"].push_back("1111");

	for (pair<string, vector<string>> contact : phoneMap) {

		string name = contact.first;
		vector<string> numbers = contact.second;

		cout << name << " : ";
		for (string num : numbers) {
			cout << num << " ";
		}

		cout << endl;

	}

	return 0;
}