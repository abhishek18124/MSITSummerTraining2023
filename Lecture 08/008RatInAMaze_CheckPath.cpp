/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> check if there exists a path from src to dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output :

		true (Yes, a path exist from src to dst)

*/

#include<iostream>

using namespace std;

int cnt = 0;

bool checkPath(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m or j == n) {

		// you've gone outside the maze therefore path does not exists

		return false;

	}

	if (i == m - 1 and j == n - 1) {

		// you are already at the destination (assume destination is not blocked)

		cnt++;

		return true;

	}

	if (maze[i][j] == 'X') {

		// you cannot go from a blocked cell to destination

		return false;

	}

	// recursive case

	// if (i == m - 1) {

	// 	// you've only one option which to move right

	// 	return checkPath(maze, m, n, i, j + 1);

	// }

	// if (j == n - 1) {

	// 	// you've only one option which to move down

	// 	return checkPath(maze, m, n, i + 1, j);

	// }

	// you've two options

	// 1. move right

	// 2. move down

	return checkPath(maze, m, n, i, j + 1) or checkPath(maze, m, n, i + 1, j);

}

int main() {

	char maze[][10] = {"0000",
	                   "0XX0",
	                   "00XX",
	                   "0000"
	                  };
	int m = 4;
	int n = 4;

	checkPath(maze, m, n, 0, 0) ? cout << "path exists" << endl : cout << "path does not exist" << endl;

	cout << cnt << endl;

	return 0;
}