class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {

        /**
         * dp[i][j]: The maximum score that Alice can acquire by considering
         *           the stones in the range [i, j].
         *
         *  TC: O(n^3)
         *  SC: O(n^2)
         */

        int n = stoneValue.size();

        vector<int> prefix(n + 1);
        for (int i = 1 ; i <= n ; ++i) {
            prefix[i] = prefix[i - 1] + stoneValue[i - 1];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return topDown(0, n - 1, prefix, dp);
    }

private:
    int topDown(
            int i, int j,
            const vector<int>& prefix,
            vector<vector<int>>& dp) {

        if (i == j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int opt = 0;
        for (int k = i ; k < j ; ++k) {
            int left = prefix[k + 1] - prefix[i];
            int right = prefix[j + 1] - prefix[k + 1];

            if (left > right) {
                opt = max(opt, right + topDown(k + 1, j, prefix, dp));
            } else if (left < right) {
                opt = max(opt, left + topDown(i, k, prefix, dp));
            } else {
                opt = max(opt, right + topDown(k + 1, j, prefix, dp));
                opt = max(opt, left + topDown(i, k, prefix, dp));
            }
        }

        return dp[i][j] = opt;
    }
};