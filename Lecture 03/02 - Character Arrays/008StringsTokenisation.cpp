#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[] = "ab$.$c.d$e...f.ghi";
	char dlim[] = ".$";

	char* token = strtok(str, dlim);

	while (token != NULL) {
		cout << token << " ";
		token = strtok(NULL, dlim);
	}

	return 0;
}