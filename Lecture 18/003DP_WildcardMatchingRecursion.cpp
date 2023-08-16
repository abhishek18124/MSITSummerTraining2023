class Solution {
public:

    bool helper(string s, string p, int m, int n, int i, int j) {

        // base case

        if (i == m) {

            bool flag = true; // assume p[j...n-1] is all '*'
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            return flag;

        }

        if (j == n) { // i != m
            return false;
        }

        // recursive case

        // check if p[j...n-1] matches with s[i...m-1]

        if (p[j] == '?' or p[j] == '*') {
            // jth character is a wildcard
            if (p[j] == '?') {
                return helper(s, p, m, n, i + 1, j + 1);
            } else { // p[j] = '*'
                return helper(s, p, m, n, i, j + 1) or helper(s, p, m, n, i + 1, j);
            }
        } else {
            // jth character is not a wildcard
            if (s[i] == p[j]) {
                return helper(s, p, m, n, i + 1, j + 1);
            } else { // s[i] != p[j]
                return false;
            }
        }

    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        return helper(s, p, m, n, 0, 0);
    }
};