class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        /**
         *  dp[i][j]: The optimal relative score the current player can
         *            obtain when there are (j - i + 1) piles remained.
         *
         *  dp[i][j] = MAX | piles[i] - dp[i + 1][j]
         *                 | piles[j] - dp[i][j - 1]
         *
         *  TC: O(n^2)
         *  SC: O(n^2)
         */

        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return topDown(0, n - 1, piles, dp) > 0;
    }

private:
    int topDown(
            int i, int j,
            const vector<int>& piles,
            vector<vector<int>>& dp) {

        if (i == j) {
            return piles[i];
        }

        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        int opt = max(
            piles[i] - topDown(i + 1, j, piles, dp),
            piles[j] - topDown(i, j - 1, piles, dp));
        return dp[i][j] = opt;
    }
};