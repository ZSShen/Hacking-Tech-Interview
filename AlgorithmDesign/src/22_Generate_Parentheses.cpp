class Solution {
public:
    vector<string> generateParenthesis(int n) {

        /**
         * https://leetcode.com/problems/generate-parentheses/
         *
         * TC: O(2 ^ (2N))
         * SC: O(N)
         */

        string config;
        vector<string> ans;

        helper(0, 0, 0, n << 1, config, ans);
        return ans;
    }

private:
    void helper(
            int L, int R, int c, int n,
            string& config,
            vector<string>& ans) {

        if (c == n) {
            if (L == R) {
                ans.push_back(config);
            }
            return;
        }

        config.push_back('(');
        helper(L + 1, R, c + 1, n, config, ans);
        config.pop_back();

        if (L > R) {
            config.push_back(')');
            helper(L, R + 1, c + 1, n, config, ans);
            config.pop_back();
        }
    }
};