class Solution {
public:

    int helper(vector<vector<int>>& dungeon, int m, int n, int i, int j) {

        // base case

        if (i == m or j == n) {
            return INT_MAX;
        }

        if (i == m - 1 and j == n - 1) {

            if (dungeon[i][j] >= 0) {
                return 1;
            }

            // dungeon[i][j] < 0
            return 1 - dungeon[i][j]; // or 1 + abs(dungeon[i][j])

        }

        // recursive case

        // 1. move right (i, j) -> (i, j+1)
        int x = helper(dungeon, m, n, i, j + 1);

        // 2. move down (i, j) -> (i+1, j)
        int y = helper(dungeon, m, n, i + 1, j);

        if (dungeon[i][j] == 0) {
            return min(x, y);
        } else if (dungeon[i][j] < 0) {
            return min(x, y) - dungeon[i][j]; // or min(x, y) + abs(dungeon[i][j])
        } else { // dungeon[i][j] > 0
            if (dungeon[i][j] >= min(x, y)) {
                return 1;
            } else {
                return min(x, y) - dungeon[i][j];
            }
        }

    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        return helper(dungeon, m, n, 0, 0);
    }
};