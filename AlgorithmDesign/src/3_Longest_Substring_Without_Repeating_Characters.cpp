class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        /**
         * https://leetcode.com/problems/longest-substring-without-repeating-characters/
         *
         * TC: O(N)
         * SC: O(1)
         */

        vector<int> freq(128);

        int n = s.length();
        int l = 0;
        int ans = 0;

        for (int r = 0 ; r < n ; ++r) {
            char ch = s[r];
            ++freq[ch];

            while (l <= r && freq[ch] > 1) {
                --freq[s[l++]];
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};