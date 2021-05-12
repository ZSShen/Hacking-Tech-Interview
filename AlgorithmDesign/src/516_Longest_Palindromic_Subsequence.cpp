class Solution {
public:
    int longestPalindromeSubseq(string s) {

        /**
         *
         *
         * dp[i][j]: The length of the the LPS within the subsutring
         * starting at offset i and ending at offset j.
         *
         * dp[i][j] = | if s[i] == s[j], 2 + dp[i + 1][j - 1]
         *            | otherwise      , max(dp[i][j - 1], dp[i + 1][j])
         *
         */

        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0 ; i < n ; ++i) {
            dp[i][i] = 1;
            if (i < n - 1) {
                dp[i][i + 1] = 1 + (s[i] == s[i + 1]);
            }
        }

        for (int l = 3 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= n - l ; ++i, ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};