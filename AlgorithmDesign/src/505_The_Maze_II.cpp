
struct Record {
    int x, y, d;

    Record(int x, int y, int d)
        : x(x), y(y), d(d)
    { }
};

class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& bgn, vector<int>& end) {

        /**
         *  TC: O(m * n * (m + n))
         *  SC: O(m * n)
         */

        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> memo(m, vector<int>(n, INT_MAX));
        memo[bgn[0]][bgn[1]] = 0;

        queue<Record> q;
        q.emplace(bgn[0], bgn[1], 0);

        while (!q.empty()) {
            auto record = q.front();
            q.pop();

            int x = record.x;
            int y = record.y;
            int d = record.d;

            for (const auto& direct : directs) {
                int nx = x;
                int ny = y;

                // Start rolling the ball.
                while (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                       maze[nx][ny] == 0) {
                    nx += direct[0];
                    ny += direct[1];
                }

                // Bounce back once hitting a wall.
                nx -= direct[0];
                ny -= direct[1];

                int nd = d + abs(nx - x) + abs(ny - y);

                // We have recorded a shorter path.
                if (nd < memo[nx][ny]) {
                    memo[nx][ny] = nd;
                    q.emplace(nx, ny, nd);
                }
            }
        }

        return memo[end[0]][end[1]] == INT_MAX ? -1 : memo[end[0]][end[1]];
    }

private:
    vector<vector<int>> directs;
};