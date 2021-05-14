
struct Node {
    bool is_word = false;
    unordered_map<char, shared_ptr<Node>> branch;
};

class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {

        /**
         * https://leetcode.com/problems/word-search-ii/
         *
         * TC: O(M * N * (3^L))
         * SC: O(L + C)
         *
         *  C: The space usage of the trie, which is proportional to the # of
         *     characters of the word vector
         */

        int m = grid.size();
        int n = grid[0].size();

        auto root = buildTrie(words);

        unordered_set<string> ans;
        string prefix;

        for (int x = 0 ; x < m ; ++x) {
            for (int y = 0 ; y < n ; ++y) {
                dfs(x, y, m, n, grid, root, prefix, ans);
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }

private:
    vector<vector<int>> directs;

    shared_ptr<Node> buildTrie(vector<string>& words) {

        auto root = make_shared<Node>();

        for (const auto& word : words) {

            auto curr = root;
            for (char ch : word) {
                if (curr->branch.count(ch) == 0) {
                    curr->branch[ch] = make_shared<Node>();
                }
                curr = curr->branch[ch];
            }
            curr->is_word = true;
        }

        return root;
    }

    void dfs(
            int x, int y, int m, int n,
            vector<vector<char>>& grid,
            shared_ptr<Node> curr,
            string& prefix,
            unordered_set<string>& ans) {

        char ch = grid[x][y];
        if (curr->branch.count(ch) == 0) {
            return;
        }

        prefix.push_back(ch);
        grid[x][y] = 0;

        curr = curr->branch[ch];
        if (curr->is_word) {
            ans.emplace(prefix);
            curr->is_word = false;
        }

        for (const auto& d : directs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!(nx >= 0 && ny >= 0 && nx < m && ny < n) ||
                grid[nx][ny] == 0) {
                continue;
            }

            dfs(nx, ny, m, n, grid, curr, prefix, ans);
        }

        grid[x][y] = ch;
        prefix.pop_back();
    }
};