class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        // x1 + y1 = x2 + y2
        // y2 = x1 + y1 - x2

        int n = grid.size();
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(n, vector<int>(n, INT_MIN)));

        int res = topDown(0, 0, 0, n, grid, dp);
        return res > 0 ? res : 0;
    }

private:
    int topDown(
            int x1, int y1, int x2, int n,
            const vector<vector<int>>& grid,
            vector<vector<vector<int>>>& dp) {

        int y2 = x1 + y1 - x2;
        if (x1 >= n || y1 >= n || x2 >= n || y2 >= n
           || grid[x1][y1] == -1 || grid[x2][y2] == -1) {
            return -1;
        }

        if (x1 == n - 1 && y1 == n - 1) {
            return grid[n - 1][n - 1];
        }

        if (dp[x1][y1][x2] != INT_MIN) {
            return dp[x1][y1][x2];
        }

        int sum = (x1 == x2 && y1 == y2) ?
            grid[x1][y1] : grid[x1][y1] + grid[x2][y2];

        int opt = topDown(x1 + 1, y1, x2 + 1, n, grid, dp);
        opt = max(opt, topDown(x1 + 1, y1, x2, n, grid, dp));
        opt = max(opt, topDown(x1, y1 + 1, x2 + 1, n, grid, dp));
        opt = max(opt, topDown(x1, y1 + 1, x2, n, grid, dp));

        // Cannot pick any cherry in the sub-problems.
        if (opt < 0) {
            return dp[x1][y1][x2] = -1;
        }

        return dp[x1][y1][x2] = opt + sum;
    }
};