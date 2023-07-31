#include<iostream>

using namespace std;

// // time : O(y)

// int f(int x, int y) {

// 	// base case

// 	if (y == 0) {

// 		// compute x^0

// 		return 1;

// 	}

// 	// recursive case

// 	// ask your friend to calculate x^(y-1)

// 	int A = f(x, y - 1);

// 	return x * A;

// }

// time : O(logy)

int f(int x, int y) {

	// base case

	if (y == 0) {

		// compute x^0

		return 1;

	}

	// recursive case

	// ask your friend to calculate x^(y/2)

	int A = f(x, y / 2);

	if (y % 2 == 0) {

		return A * A;

	}

	// y is odd

	return A * A * x;

}

int main() {

	int x = 2;
	int y = 10;

	cout << f(x, y) << endl;

	return 0;
}