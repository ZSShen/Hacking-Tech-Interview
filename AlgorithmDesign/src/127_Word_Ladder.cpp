class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        /**
         * https://leetcode.com/problems/word-ladder/
         *
         *  N: The number of dictionary words.
         *  L: The averaged length of a word.
         *
         *  TC: O(N * (26 ^ L))
         *  SC: O(N * L)
         */

        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<string> q;
        q.emplace(beginWord);

        int depth = 0;

        while (!q.empty()) {
            int n = q.size();
            ++depth;

            for (int i = 0 ; i < n ; ++i) {
                auto cand = q.front();
                q.pop();

                int len = cand.length();
                for (int j = 0 ; j < len ; ++j) {
                    char back = cand[j];

                    for (char ch = 'a' ; ch <= 'z' ; ++ch) {
                        cand[j] = ch;

                        if (dict.count(cand) == 0) {
                            continue;
                        }

                        if (cand == endWord) {
                            return depth + 1;
                        }

                        dict.erase(cand);
                        q.emplace(cand);
                    }

                    cand[j] = back;
                }
            }
        }

        return 0;
    }
};
