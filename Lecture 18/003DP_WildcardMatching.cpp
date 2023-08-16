class Solution {
public:

    bool helper(string s, string p, int m, int n) {

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        for (int j = 0; j <= n; j++) {

            bool flag = true; // assume p[j...n-1] has all '*'
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[m][j] = flag;

        }

        for (int i = 0; i <= m; i++) {

            if (i == m) dp[i][n] = true;
            else dp[i][n] = false;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // check if p[j...n-1] matches s[i...m-1]

                if (p[j] == '?' or p[j] == '*') {
                    // jth character is a wildcard
                    if (p[j] == '?') {
                        dp[i][j] = dp[i + 1][j + 1];
                    } else { // p[j] = '*'
                        dp[i][j] = dp[i][j + 1] or dp[i + 1][j];
                    }
                } else {
                    // jth character is not a wildcard
                    if (s[i] == p[j]) {
                        dp[i][j] = dp[i + 1][j + 1];
                    } else { // s[i] != p[j]
                        dp[i][j] = false;
                    }
                }

            }
        }

        return dp[0][0]; // at the (0, 0)th index of dp[], we store f(0, 0)

    }

    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        return helper(s, p, m, n);

    }
};