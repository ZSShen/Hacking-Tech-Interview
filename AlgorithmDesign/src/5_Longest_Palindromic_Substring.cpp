class Solution {
public:
    string longestPalindrome(string s) {

        /**
         * https://leetcode.com/problems/longest-palindromic-substring/
         *
         * TC: O(N^2)
         * SC: O(N^2)
         *
         * dp[i][j]: Whether the substring (i, j) is palindromic.
         *
         * dp[i][j] = | if s[i] == s[j], dp[i + 1][j - 1]
         *            | otherwise      , false
         *
         */

        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n));
        int len = 1, bgn = 0;

        for (int i = 0 ; i < n ; ++i) {
            dp[i][i] = true;
            if (i < n - 1) {
                dp[i][i + 1] = s[i] == s[i + 1];
                if (dp[i][i + 1]) {
                    len = 2;
                    bgn = i;
                }
            }
        }

        for (int l = 3 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= n - l ; ++i, ++j) {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                if (dp[i][j]) {
                    len = l;
                    bgn = i;
                }
            }
        }

        return s.substr(bgn, len);
    }
};