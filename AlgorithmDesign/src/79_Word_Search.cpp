class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    bool exist(vector<vector<char>>& grid, string word) {

        int m = grid.size();
        int n = grid[0].size();
        int l = word.length();

        for (int x = 0 ; x < m ; ++x) {
            for (int y = 0 ; y < n ; ++y) {
                bool res = dfs(x, y, m, n, grid, word, 0, l);
                if (res) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    vector<vector<int>> directs;

    bool dfs(
            int x, int y, int m, int n,
            vector<vector<char>>& grid,
            const string& word,
            int offset, int length) {

        char ch = grid[x][y];
        if (ch != word[offset]) {
            return false;
        }

        ++offset;
        if (offset == length) {
            return true;
        }

        grid[x][y] = 0;

        for (const auto& d : directs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!(nx >= 0 && ny >= 0 && nx < m && ny < n) ||
                grid[nx][ny] == 0) {
                continue;
            }

            bool res = dfs(nx, ny, m, n, grid, word, offset, length);
            if (res) {
                return true;
            }
        }

        grid[x][y] = ch;
        return false;
    }
};
