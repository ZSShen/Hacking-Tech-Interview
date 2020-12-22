class Solution {
public:
    bool winnerSquareGame(int n) {

        /**
         * dp[i]: Whether the current player can win the game by picking stones
         *        in the range [i, n).
         *
         * dp[i] = OR { !dp[i + j * j] | i + j * j <= n }
         *              ^^^^^^^^^^^^^^
         *         Take negation since a player always needs to push his
         *         rival to lose the game. Thus, if there is a DP state where
         *         his rival will lose, then the current player should win.
         */

        vector<char> dp(n, -1);
        return topDown(0, n, dp);
    }

private:
    bool topDown(
        int i, int n, vector<char>& dp) {

        if (i == n) {
            return false;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        bool res = false;
        for (int j = 1 ; i + j * j <= n ; ++j) {
            res = res || !topDown(i + j * j, n, dp);
            if (res) {
                break;
            }
        }
        return dp[i] = res;
    }
};