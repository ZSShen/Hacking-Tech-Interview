class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        /**
         *  dp[i]: The maximum score difference Alice can generate
         *         by considering the remaining stones within the range [i, n).
         *
         *  dp[i] = MAX | stones[i] - dp[i + 1]
         *              | stones[i] + stones[i + 1] - dp[i + 2]
         *              | stones[i] + stones[i + 1] + stones[i + 2] - dp[i + 3]
         *
         *  TC: O(n)
         *  SC: O(n)
         */

        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);

        int res = topDown(0, n, stoneValue, dp);
        if (res == 0) {
            return "Tie";
        }
        return res > 0 ? "Alice" : "Bob";
    }

private:
    int topDown(
            int i, int n,
            const vector<int>& stones,
            vector<int>& dp) {

        if (i == n) {
            return 0;
        }

        if (dp[i] != INT_MIN) {
            return dp[i];
        }

        int score = stones[i];
        int opt = score - topDown(i + 1, n, stones, dp);

        // Pick 2 stones.
        if (i + 1 < n) {
            score += stones[i + 1];
            opt = max(opt, score - topDown(i + 2, n, stones, dp));
        }

        // Pick 3 stones.
        if (i + 2 < n) {
            score += stones[i + 2];
            opt = max(opt, score - topDown(i + 3, n, stones, dp));
        }

        return dp[i] = opt;
    }
};