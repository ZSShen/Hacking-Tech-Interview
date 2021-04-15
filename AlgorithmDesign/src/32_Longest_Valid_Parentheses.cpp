class Solution {
public:
    int longestValidParentheses(string s) {

        /**
         * https://leetcode.com/problems/longest-valid-parentheses/
         *
         * TC: O(N)
         * SC: O(N)
         */

        int n = s.length(), ans = 0;

        stack<int> stk;
        stk.emplace(-1);

        for (int i = 0 ; i < n ; ++i) {
            if (s[i] == '(') {
                stk.emplace(i);
            } else {
                if (stk.top() != -1 && s[stk.top()] == '(') {
                    stk.pop();
                    ans = max(ans, i - stk.top());
                } else {
                    stk.emplace(i);
                }
            }
        }

        return ans;
    }
};