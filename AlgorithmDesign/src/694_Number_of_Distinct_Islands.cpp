class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    int numDistinctIslands(vector<vector<int>>& grid) {

        /**
         * TC: O(m * n)
         * SC: O(m * n)
         */

        int m = grid.size();
        int n = grid[0].size();

        unordered_set<string> islands;

        for (int x = 0 ; x < m ; ++x) {
            for (int y = 0 ; y < n ; ++y) {
                if (grid[x][y] == 0) {
                    continue;
                }

                vector<pair<int, int>> points;
                dfs(x, y, m, n, grid, points);
                auto code = encode(points);
                islands.emplace(code);
            }
        }

        return islands.size();
    }

private:
    vector<vector<int>> directs;

    string encode(vector<pair<int, int>>& points) {

        string code;
        int ox = points[0].first;
        int oy = points[0].second;

        for (const auto& p : points) {
            code += to_string(p.first - ox) + to_string(p.second - oy);
        }

        return code;
    }

    void dfs(
            int x, int y, int m, int n,
            vector<vector<int>>& grid,
            vector<pair<int, int>>& points) {

        grid[x][y] = 0;
        points.push_back({x, y});

        for (const auto& d : directs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!(nx >= 0 && ny >= 0 && nx < m && ny < n) ||
                grid[nx][ny] == 0) {
                continue;
            }

            dfs(nx, ny, m, n, grid, points);
        }
    }
};
