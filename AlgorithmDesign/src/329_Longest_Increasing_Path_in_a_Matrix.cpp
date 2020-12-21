class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        /**
         *  dp[i][j]: The lenngth of the longest increasing path starting
         *            from the cell (i, j).
         *
         *  TC: O(m * n)
         *  SC: O(m * n)
         */

        int m = matrix.size();
        if (m == 0) {
            return 0;
        }

        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n));
        int ans = 0;
        for (int r = 0 ; r < m ; ++r) {
            for (int c = 0 ; c < n ; ++c) {
                ans = max(ans, topDown(r, c, m, n, -1, matrix, dp));
            }
        }

        return ans;
    }

private:
    int topDown(
            int r, int c, int m, int n, int h,
            const vector<vector<int>>& mtx,
            vector<vector<int>>& dp) {

        if (r < 0 || c < 0 || r >= m || c >= n || h >= mtx[r][c]) {
            return 0;
        }

        if (dp[r][c] > 0) {
            return dp[r][c];
        }

        int opt = 1 + topDown(r - 1, c, m, n, mtx[r][c], mtx, dp);
        opt = max(opt, 1 + topDown(r + 1, c, m, n, mtx[r][c], mtx, dp));
        opt = max(opt, 1 + topDown(r, c - 1, m, n, mtx[r][c], mtx, dp));
        opt = max(opt, 1 + topDown(r, c + 1, m, n, mtx[r][c], mtx, dp));
        return dp[r][c] = opt;
    }
};