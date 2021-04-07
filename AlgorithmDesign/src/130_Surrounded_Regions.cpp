class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    void solve(vector<vector<char>>& board) {

        /**
         * https://leetcode.com/problems/surrounded-regions/
         *
         * TC: O(m * n)
         * SC: O(m * n)
         */

        int m = board.size();
        int n = board[0].size();

        // Check the first and the last rows.
        for (int j = 0 ; j < n ; ++j) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, m, n);
            }
            if (board[m - 1][j] == 'O') {
                dfs(board, m - 1, j, m, n);
            }
        }

        // Check the first and the last columns.
        for (int i = 0 ; i < m ; ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, m, n);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1, m, n);
            }
        }

        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    vector<vector<int>> directs;

    void dfs(
            vector<vector<char>>& board,
            int x, int y, int m, int n) {

        board[x][y] = 'V';

        for (const auto& d : directs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!(nx >= 0 && ny >= 0 && nx < m && ny < n) ||
                board[nx][ny] != 'O') {
                continue;
            }
            dfs(board, nx, ny, m, n);
        }
    }
};