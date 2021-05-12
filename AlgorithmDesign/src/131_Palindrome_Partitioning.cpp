class Solution {
public:
    vector<vector<string>> partition(string s) {

        /**
         * https://leetcode.com/problems/palindrome-partitioning/
         *
         * TC: O(N * 2^N)
         * SC: O(N)
         */

        int n = s.length();
        vector<vector<bool>> palin(n, vector<bool>(n));

        for (int i = 0 ; i < n ; ++i) {
            palin[i][i] = true;
            if (i < n - 1) {
                palin[i][i + 1] = s[i] == s[i + 1];
            }
        }

        for (int l = 3 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= n - l ; ++i, ++j) {
                palin[i][j] = (s[i] == s[j]) && palin[i + 1][j - 1];
            }
        }

        vector<string> config;
        vector<vector<string>> ans;
        helper(0, s.length(), s, palin, config, ans);
        return ans;
    }

private:
    void helper(
            int bgn, int end,
            const string& s,
            vector<vector<bool>>& palin,
            vector<string>& config,
            vector<vector<string>>& ans) {

        if (bgn == end) {
            ans.emplace_back(config);
            return;
        }

        for (int i = bgn; i < end ; ++i) {
            if (!palin[bgn][i]) {
                continue;
            }

            config.emplace_back(s.substr(bgn, i - bgn + 1));
            helper(i + 1, end, s, palin, config, ans);
            config.pop_back();
        }
    }
};