/*

Example :
	Input : N = 5, W = 4
			weights[] = {1, 2, 3, 2, 2}
			profits[] = {8, 4, 1, 5, 3}
	Output: 13

*/

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int> weights, vector<int> profits,
              int N, int i, int w) {

	// base case

	if (i == N) {
		return 0;
	}

	if (w == 0) {
		return 0;
	}

	// recursive case

	// take a sequence of decisions for the object i, i+1, i+2, ..., n-1 such that current capacity of the knapsack is 'w'

	// decide for the ith object

	if (weights[i] > w) {
		// exclude the ith object from the knapsack
		return maxProfit(weights, profits, N, i + 1, w);
	}

	// 1. include the ith object into the knapsack
	int x = maxProfit(weights, profits, N, i + 1, w - weights[i]);

	// 2. exclude the ith object from the knapsack
	int y = maxProfit(weights, profits, N, i + 1, w);

	return max(profits[i] + x, y);

}


// time : O(N.W)

// space : N.W (due to dp[]) + N (due to function call stack) ~ O(N.W)

int maxProfitTopDown(vector<int> weights, vector<int> profits,
                     int N, int i, int w, vector<vector<int>>& dp) {

	// lookup
	if (dp[i][w] != -1) {
		return dp[i][w];
	}

	// base case

	if (i == N) {
		return dp[i][w] = 0;
	}

	if (w == 0) {
		return dp[i][w] = 0;
	}

	// recursive case

	// take a sequence of decisions for the object i, i+1, i+2, ..., n-1 such that current capacity of the knapsack is 'w'

	// decide for the ith object

	if (weights[i] > w) {
		// exclude the ith object from the knapsack
		return dp[i][w] = maxProfitTopDown(weights, profits, N, i + 1, w, dp);
	}

	// 1. include the ith object into the knapsack
	int x = maxProfitTopDown(weights, profits, N, i + 1, w - weights[i], dp);

	// 2. exclude the ith object from the knapsack
	int y = maxProfitTopDown(weights, profits, N, i + 1, w, dp);

	return dp[i][w] = max(profits[i] + x, y);

}


int main() {

	int N = 5;
	int W = 4;

	vector<int> weights = {1, 2, 3, 2, 2};
	vector<int> profits = {8, 4, 1, 5, 3};

	cout << maxProfit(weights, profits, N, 0, W) << endl;

	vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));

	cout << maxProfitTopDown(weights, profits, N, 0, W, dp) << endl;

	return 0;
}