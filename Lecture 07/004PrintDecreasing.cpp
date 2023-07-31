#include<iostream>

using namespace std;

void f(int n) {

	// base case

	if (n == 0) {
		return;
	}

	// recursive case

	cout << n << " ";

	// ask your friend to print nos. from n-1 to 1

	f(n - 1);

}

int main() {

	int n = 5;

	f(n);

	return 0;
}