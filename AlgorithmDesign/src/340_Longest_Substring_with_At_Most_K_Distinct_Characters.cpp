class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {

        /**
         * https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
         *
         * TC: O(n)
         * SC: O(1)
         */

        int n = s.length();
        int l = 0;

        vector<int> freq(256);
        int count = 0;
        int ans = 0;

        for (int r = 0 ; r < n ; ++r) {
            char ch = s[r];
            ++freq[ch];

            if (freq[ch] == 1) {
                ++count;
            }

            while (count > k && l <= r) {
                --freq[s[l]];
                if (freq[s[l]] == 0) {
                    --count;
                }
                ++l;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};