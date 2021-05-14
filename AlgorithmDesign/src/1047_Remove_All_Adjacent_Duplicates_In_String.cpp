class Solution {
public:
    string removeDuplicates(string s) {

        /**
         * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
         *
         *  TC: O(N)
         *  SC: O(N)
         */

        string ans;

        for (char ch : s) {
            bool match = false;

            while (!ans.empty() && ans.back() == ch) {
                ans.pop_back();
                match = true;
            }

            if (!match) {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};