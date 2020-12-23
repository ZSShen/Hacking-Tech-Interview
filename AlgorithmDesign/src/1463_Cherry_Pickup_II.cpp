class Solution {
public:
    Solution()
        : directs({
            {-1, -1},
            {-1,  0},
            {-1,  1},
            { 0, -1},
            { 0,  0},
            { 0,  1},
            { 1, -1},
            { 1,  0},
            { 1,  1}
        })
    { }

    int cherryPickup(vector<vector<int>>& grid) {

        /**
         *  dp[r][c1][c2]: With the backward view, the maximum number of cherries
         *                 that the two robots can collect when they are back
         *                 to the grid cells (r, c1) and (r, c2), respectively.
         *
         *  TC: O(m * n^2)
         *  SC: O(m * n^2)
         */

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, -1)));

        return topDown(0, 0, n - 1, m, n, grid, dp);
    }

private:
    vector<vector<int>> directs;

    int topDown(
            int r, int c1, int c2, int m, int n,
            const vector<vector<int>>& grid,
            vector<vector<vector<int>>>& dp) {

        if (r == m) {
            return 0;
        }

        if (dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }

        int sum = (c1 != c2) ? grid[r][c1] + grid[r][c2] : grid[r][c1];
        int opt = 0;

        for (const auto& direct : directs) {
            int nc1 = c1 + direct[0];
            int nc2 = c2 + direct[1];
            if (nc1 < 0 || nc1 >= n || nc2 < 0 || nc2 >= n) {
                continue;
            }
            opt = max(opt, topDown(r + 1, nc1, nc2, m, n, grid, dp));
        }

        sum += opt;
        return dp[r][c1][c2] = sum;
    }
};