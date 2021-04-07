class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    int numIslands(vector<vector<char>>& grid) {

        /**
         * https://leetcode.com/problems/number-of-islands/
         *
         * TC: O(m * n)
         * SC: O(m * n)
         */

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int x = 0 ; x < m ; ++x) {
            for (int y = 0 ; y < n ; ++y) {
                if (grid[x][y] == '1') {
                    ++ans;
                    dfs(grid, x, y, m, n);
                }
            }
        }

        return ans;
    }

private:
    vector<vector<int>> directs;

    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {

        grid[x][y] = '0';

        for (const auto& d : directs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!(nx >= 0 && ny >= 0 && nx < m && ny < n) ||
               grid[nx][ny] == '0') {
                continue;
            }
            dfs(grid, nx, ny, m, n);
        }
    }
};
