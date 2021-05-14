class Solution {
public:
    string reverseWords(string s) {

        /**
         * https://leetcode.com/problems/reverse-words-in-a-string/
         *
         *  TC: O(N)
         *  SC: O(1)
         *
         *  the sky is blue
         *
         *  eht yks si eulb
         *
         *  blue is sky the
         */

        // Trim extra whitespaces.
        int n = s.length();
        int l = 0;
        for (int r = 0 ; r < n ; ++r) {
            if (s[r] == ' ') {
                continue;
            }

            while (r < n && s[r] != ' ') {
                s[l++] = s[r++];
            }
            s[l++] = ' ';
        }

        while (n >= l) {
            s.pop_back();
            --n;
        }

        // Reverse each word.
        for (int i = 0 ; i < n ; ++i) {
            int l = i, r = i;
            while (r < n && s[r] != ' ') {
                ++r;
            }

            i = r;
            --r;

            while (l <= r) {
                swap(s[l++], s[r--]);
            }
        }

        reverse(s.begin(), s.end());
        return s;
    }
};