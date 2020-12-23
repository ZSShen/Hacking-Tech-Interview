class Solution {
public:
    Solution()
        : directs({
            {1, 0},
            {0, 1},
            {1, 1},
            {1, -1},
            {-1, 0},
            {0, -1},
            {-1, -1},
            {-1, 1}})
    { }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        /**
         *  TC: O(m * n)
         *  TC: O(m * n)
         */

        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            ++level;

            for (int i = 0 ; i < size ; ++i) {
                auto rec = q.front();
                q.pop();

                int x = rec.first;
                int y = rec.second;

                if (x == m - 1 && y == n - 1) {
                    return level;
                }

                for (const auto& d : directs) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                        grid[nx][ny] == 1) {
                        continue;
                    }

                    q.push({nx, ny});
                    grid[nx][ny] = 1;
                }
            }
        }

        return -1;
    }

private:
    vector<vector<int>> directs;
};