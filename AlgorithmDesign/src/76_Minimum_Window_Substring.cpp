class Solution {
public:
    string minWindow(string s, string t) {

        /**
         * https://leetcode.com/problems/minimum-window-substring/
         *
         * TC: O(n)
         * SC: O(n)
         *
         *                l
         *                   r
         *  S = "ADOBECODEBANC"
         *  T = "ABC"
         *
         *  BT = {A:1, B:1, C:1}
         *  BS = {A:1, B:1, C:1, D:0, E:0, N:1, O:0,}
         */

        vector<int> bag_t(256, 0);
        vector<int> bag_s(256, 0);

        unordered_set<int> set;

        for (char ch : t) {
            set.emplace(ch);
            ++bag_t[ch];
        }

        int cnt_t = set.size();
        int cnt_s = 0;

        int n = s.length();
        int ans = n;
        int bgn = 0, end = -1;

        int l = 0;
        for (int r = 0 ; r < n ; ++r) {
            char ch = s[r];
            ++bag_s[ch];

            if (bag_s[ch] == bag_t[ch]) {
                ++cnt_s;
            }

            while (l <= r && cnt_s == cnt_t) {
                int window = r - l + 1;
                if (window <= ans) {
                    ans = window;
                    bgn = l;
                    end = r;
                }

                ch = s[l++];
                --bag_s[ch];
                if (bag_s[ch] == bag_t[ch] - 1) {
                    --cnt_s;
                }
            }
        }

        return s.substr(bgn, end - bgn + 1);
    }
};