class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        /**
         *  n: The number of words.
         *  l: The averaged length of a word.
         *
         *  TC: O(n * (26 ^ l))
         *  SC: O(n * l)
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
