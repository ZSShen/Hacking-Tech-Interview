class Solution {
public:
    bool isValid(string s) {

        /**
         * https://leetcode.com/problems/valid-parentheses/
         *
         * TC: O(N)
         * SC: O(N)
         */

        std::stack<char> stk;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
                continue;
            }

            if (stk.empty()) {
                return false;
            }

            if (ch == ')') {
                if (stk.top() == '(') {
                    stk.pop();
                } else {
                    break;
                }
            } else if (ch == ']') {
                if (stk.top() == '[') {
                    stk.pop();
                } else {
                    break;
                }
            } else {
                if (stk.top() == '{') {
                    stk.pop();
                } else {
                    break;
                }
            }
        }

        return stk.empty();
    }
};