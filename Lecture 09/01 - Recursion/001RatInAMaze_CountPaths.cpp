#include<iostream>

using namespace std;

// int cnt = 0;

// bool checkPath(char maze[][10], int m, int n, int i, int j) {

// 	// base case

// 	if (i == m or j == n) {

// 		// you've gone outside the maze therefore path does not exists

// 		return false;

// 	}

// 	if (i == m - 1 and j == n - 1) {

// 		// you are already at the destination (assume destination is not blocked)

// 		cnt++;

// 		return true;

// 	}

// 	if (maze[i][j] == 'X') {

// 		// you cannot go from a blocked cell to destination

// 		return false;

// 	}

// 	// recursive case

// 	// you've two options

// 	// 1. move right

// 	bool X = checkPath(maze, m, n, i, j + 1);

// 	// 2. move down

// 	bool Y = checkPath(maze, m, n, i + 1, j);

// 	return  X or Y;

// }


int countPaths(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m or j == n) {

		// you've gone outside the maze therefore path does not exists

		return 0;

	}

	if (i == m - 1 and j == n - 1) {

		// you are already at the destination (assume destination is not blocked)

		return 1;

	}

	if (maze[i][j] == 'X') {

		// you cannot go from a blocked cell to destination

		return 0;

	}

	// recursive case

	// you've two options

	// 1. move right

	int X = countPaths(maze, m, n, i, j + 1);

	// 2. move down

	int Y = countPaths(maze, m, n, i + 1, j);

	return  X + Y;

}

int main() {

	char maze[][10] =

	{	"0000",
		"00X0",
		"000X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	// checkPath(maze, m, n, 0, 0) ? cout << "path exists" << endl : cout << "path does not exist" << endl;

	// cout << cnt << endl;

	cout << countPaths(maze, m, n, 0, 0) << endl;

	return 0;
}