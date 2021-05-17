
class DSU {
public:
    DSU(int n)
        : count(n), parent(n) {

        for (int i = 0 ; i < n ; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) {
            parent[py] = px;
            --count;
        }
    }

    int query() {
        return count;
    }

private:
    int count;
    vector<int> parent;
};


class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {

        /**
         * https://leetcode.com/problems/similar-string-groups/
         *
         * TC: O((N^2) * L * log(*N))
         * SC: O(N)
         */

        int n = strs.size();
        DSU set(n);

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < i ; ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    set.merge(i, j);
                }
            }
        }

        return set.query();
    }

private:
    bool isSimilar(const string& s, const string& t) {

        int n = s.length();
        int count = 0;

        for (int i = 0 ; i < n ; ++i) {
            if (s[i] != t[i]) {
                ++count;
            }
            if (count > 2) {
                return false;
            }
        }

        return count == 0 || count == 2;
    }
};