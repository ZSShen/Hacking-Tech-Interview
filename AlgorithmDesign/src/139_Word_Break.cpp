class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        /**
         * https://leetcode.com/problems/word-break/
         *
         * dp[i]: Whether the prefix ending at offset i is composed of the
         * dictionary words.
         *
         * dp[i] = OR { dp[j] && s.substr(j, i) is in dict }
         *
         * TC: O(N * W * L)
         *      N => Length of s
         *      W => Number of dictionary words
         *      L => Average length of dictionary words
         *
         * SC: O(N)
         */

        int n = s.length();

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0 ; i <= n ; ++i) {
            if (!dp[i]) {
                continue;
            }

            for (const auto& word : wordDict) {
                int l = word.length();
                if (i + l > n) {
                    continue;
                }

                auto prefix = s.substr(i, l);
                if (prefix == word) {
                    dp[i + l] = true;
                }
            }
        }

        return dp[n];
    }
};