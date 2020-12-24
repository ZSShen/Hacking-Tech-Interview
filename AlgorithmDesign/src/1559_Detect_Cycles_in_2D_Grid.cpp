class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    bool containsCycle(vector<vector<char>>& grid) {

        /**
         * TC: O(m * n)
         * SC: O(m * n)
         */

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visit(m, vector<bool>(n));

        for (int x = 0 ; x < m ; ++x) {
            for (int y = 0 ; y < n ; ++y) {
                if (visit[x][y]) {
                    continue;
                }

                visit[x][y] = true;
                bool res = dfs(x, y, -1, -1, m, n, grid, visit, grid[x][y]);
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
            int x, int y, int px, int py, int m, int n,
            vector<vector<char>>& grid,
            vector<vector<bool>>& visit,
            char ch) {

        for (const auto& d : directs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!(nx >= 0 && ny >= 0 && nx < m && ny < n) ||
                (nx == px && ny == py) ||
                grid[nx][ny] != ch) {
                continue;
            }

            // Find a cycle containing at least 4 characters.
            if (visit[nx][ny]) {
                return true;
            }

            visit[nx][ny] = true;
            bool res = dfs(nx, ny, x, y, m, n, grid, visit, ch);
            if (res) {
                return true;
            }
        }

        return false;
    }
};