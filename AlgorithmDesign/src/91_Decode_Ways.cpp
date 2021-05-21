class Solution {
public:
    int numDecodings(string s) {

        /**
         * https://leetcode.com/problems/decode-ways/
         *
         * TC: O(N)
         * SC: O(N)
         *
         * dp[i] = dp[i - 1] * (# of ways to convert s[i]) +
         *         dp[i - 2] * (# of ways to convert s[i - 1] & s[i])
         *
         * e.g.
         *  12  -> AB, L
         *  226 -> BBF, BZ, VF
         */

        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1 ; i <= n ; ++i) {
            dp[i] = dp[i - 1] * countOneDigit(s, i - 1);
            if (i >= 2) {
                dp[i] += dp[i - 2] * countTwoDigits(s, i - 2, i - 1);
            }
        }

        return dp[n];
    }

private:
    int countOneDigit(const string& s, int r) {
        return s[r] != '0' ? 1 : 0;
    }

    int countTwoDigits(const string& s, int l, int r) {

        if (s[l] == '1') {
            return 1;
        }
        if (s[l] == '2') {
            if ('0' <= s[r] && s[r] <= '6') {
                return 1;
            }
        }

        return 0;
    }
};