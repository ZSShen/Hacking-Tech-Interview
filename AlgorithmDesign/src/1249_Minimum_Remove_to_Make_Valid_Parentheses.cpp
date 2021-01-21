class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> stack;

        int n = s.length();
        for (int i = 0 ; i < n ; ++i) {
            if (s[i] == '(') {
                stack.emplace(i);
            } else if (s[i] == ')') {
                if (!stack.empty()) {
                    stack.pop();
                } else {
                    s[i] = 0;
                }
            }
        }

        while (!stack.empty()) {
            s[stack.top()] = 0;
            stack.pop();
        }

        string ans;
        for (int i = 0 ; i < n ; ++i) {
            if (s[i] != 0) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};