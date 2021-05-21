class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        /**
         * https://leetcode.com/problems/coin-change/
         *
         *  TC: O(amount * C)
         *  SC: O(amount)
         *
         *  dp[i]: The minimum number of coins needed to
         *         make up i dollars.
         *
         *  dp[i] =  MIN  { dp[i - coin[j]] } + 1
         *          0<=j<C
         */

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int c : coins) {
            for (int i = c ; i <= amount ; ++i) {
                if (dp[i - c] == INT_MAX) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }

        return dp[amount] < INT_MAX ? dp[amount] : -1;
    }
};