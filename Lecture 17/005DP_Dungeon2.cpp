class Solution {
public:

    int helper(vector<vector<int>>& grid, int m, int n) {

        // time : O(mn)
        // space : O(mn)

        vector<vector<int>> dp(m + 1, n + 1);

        for (int i = 0; i <= m; i++) {
            dp[i][n] = INT_MAX;
        }

        for (int j = 0; j <= n; j++) {
            dp[m][j] = INT_MAX;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 and j == n - 1) {
                    if (grid[i][j] >= 0) dp[i][j] = 1;
                    else dp[i][j] = 1 - grid[i][j];
                } else {
                    int x = dp[i][j + 1];
                    int y = dp[i + 1][j];
                    if (grid[i][j] == 0) dp[i][j] = min(x, y);
                    else if (grid[i][j] < 0) dp[i][j] = min(x, y) - grid[i][j];
                    else if (grid[i][j] > 0 and grid[i][j] >= min(x, y)) dp[i][j] = 1;
                    else dp[i][j] = min(x, y) - grid[i][j];

                }

            }
        }

        return dp[0][0];

    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        return helper(dungeon, m, n);
    }
};