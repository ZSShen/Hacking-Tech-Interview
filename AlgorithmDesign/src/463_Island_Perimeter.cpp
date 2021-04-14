class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    int islandPerimeter(vector<vector<int>>& grid) {

        /**
         * https://leetcode.com/problems/island-perimeter/
         *
         * TC: O(M * N)
         * SC: O(1)
         */

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for (int x = 0 ; x < m ; ++x) {
            for (int y = 0 ; y < n ; ++y) {
                if (grid[x][y] == 0) {
                    continue;
                }

                for (auto d : directs) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if (isWateredArea(grid, nx, ny, m, n)) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }

private:
    vector<vector<int>> directs;

    bool isWateredArea(
            const vector<vector<int>>& grid,
            int x, int y, int m, int n) {

        if (x < 0 || y < 0 || x >= m || y >= n) {
            return true;
        }

        return grid[x][y] == 0;
    }
};