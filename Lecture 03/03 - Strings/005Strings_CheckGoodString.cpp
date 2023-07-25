#include<iostream>
#include<algorithm>

using namespace std;

bool isGoodString(string str) {

	for (int i = 0; i < str.size(); i++) {

		char ch = str[i];

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is a consonant
			return false;
		}

	}

	return true;

}

int main() {

	string str = "uoixea";

	isGoodString(str) ? cout << "good string" << endl :
	                         cout << "not a good string" << endl;


	return 0;
}