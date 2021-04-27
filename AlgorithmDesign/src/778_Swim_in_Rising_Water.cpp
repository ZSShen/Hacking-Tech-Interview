
class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    int swimInWater(vector<vector<int>>& grid) {

        /**
         * https://leetcode.com/problems/swim-in-rising-water/
         *
         *  TC: O(N^2 log(N^2)) = O(N^2 log(N))
         *  SC: O(N^2)
         */

        int n = grid.size();

        int l = 0, r = n * n - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (bfs(grid, n, m)) {
                r = m;
            } else {
                l = m;
            }
        }

        if (bfs(grid, n, l)) {
            return l;
        }
        if (bfs(grid, n, r)) {
            return r;
        }
        return -1;
    }

private:
    vector<vector<int>> directs;

    bool bfs(vector<vector<int>>& grid, int n, int h) {

        if (h < grid[0][0]) {
            return false;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<bool>> visit(n, vector<bool>(n, false));
        visit[0][0] = true;

        while (!q.empty()) {
            auto pair = q.front();
            q.pop();

            int r = pair.first;
            int c = pair.second;

            for (const auto& d : directs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (!(nr >= 0 && nc >= 0 && nr < n && nc < n) ||
                    visit[nr][nc] ||
                    grid[nr][nc] > h) {
                    continue;
                }

                visit[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        return visit[n - 1][n - 1];
    }
};