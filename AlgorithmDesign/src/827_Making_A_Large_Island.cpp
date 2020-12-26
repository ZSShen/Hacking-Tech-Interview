class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    int largestIsland(vector<vector<int>>& grid) {

        /**
         * TC: O(m * n)
         * SC: O(m * n)
         */

        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int, int> islands;
        int color = 2;
        int ans = 0;

        for (int x = 0 ; x < m ; ++x) {
            for (int y = 0 ; y < n ; ++y) {
                if (grid[x][y] != 1) {
                    continue;
                }

                int area = dfs(x, y, m, n, color, grid);
                islands[color++] = area;
                ans = max(ans, area);
            }
        }

        for (int x = 0 ; x < m ; ++x) {
            for (int y = 0 ; y < n ; ++y) {
                if (grid[x][y] != 0) {
                    continue;
                }

                unordered_set<int> pick;
                int area = 1;

                for (const auto& d : directs) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (!(nx >= 0 && ny >= 0 && nx < m && ny < n) ||
                        grid[nx][ny] <= 1 ||
                        pick.count(grid[nx][ny]) == 1) {
                        continue;
                    }

                    area += islands[grid[nx][ny]];
                    pick.emplace(grid[nx][ny]);
                }

                ans = max(ans, area);
            }
        }

        return ans;
    }

private:
    vector<vector<int>> directs;

    int dfs(
            int x, int y, int m, int n,
            int color,
            vector<vector<int>>& grid) {

        int area = 1;
        grid[x][y] = color;

        for (const auto& d : directs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!(nx >= 0 && ny >= 0 && nx < m && ny < n) ||
                grid[nx][ny] != 1) {
                continue;
            }

            area += dfs(nx, ny, m, n, color, grid);
        }

        return area;
    }
};