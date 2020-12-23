class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {

        /**
         *  Use DFS with flood and fill to find the islands that are not
         *  connected to the borderline.
         *
         *  TC: O(n^2)
         *  SC: O(n^2)
         */

        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (grid[i][j] == 0) {
                    count += dfs(i, j, m, n, grid);
                }
            }
        }

        return count;
    }

private:
    bool dfs(
            int x, int y, int m, int n,
            vector<vector<int>>& grid) {

        if (x < 0 || y < 0 || x >= m || y >= n) {
            return false;
        }
        if (grid[x][y] == 1) {
            return true;
        }

        grid[x][y] = 1;

        bool left = dfs(x, y - 1, m, n, grid);
        bool right = dfs(x, y + 1, m, n, grid);
        bool up = dfs(x - 1, y, m, n, grid);
        bool down = dfs(x + 1, y, m, n, grid);

        return left && right && up && down;
    }
};