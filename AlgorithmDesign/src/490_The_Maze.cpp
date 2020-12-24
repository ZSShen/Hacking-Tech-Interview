class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    bool hasPath(vector<vector<int>>& maze, vector<int>& begin, vector<int>& end) {

        /**
         *  TC: O(m * n * (m + n))
         *  SC: O(m * n)
         */

        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({begin[0], begin[1]});

        vector<vector<bool>> visit(m, vector<bool>(n));
        visit[begin[0]][begin[1]] = true;

        while (!q.empty()) {
            auto rec = q.front();
            q.pop();

            int x = rec.first;
            int y = rec.second;

            for (const auto& d : directs) {
                int nx = x + d[0];
                int ny = y + d[1];

                // Start rolling the ball.
                while ((nx >= 0 && ny >= 0 && nx < m && ny < n) &&
                        maze[nx][ny] == 0) {
                    nx += d[0];
                    ny += d[1];
                }

                // Bounce back once hitting the wall.
                nx -= d[0];
                ny -= d[1];

                if (nx == end[0] && ny == end[1]) {
                    return true;
                }

                if (visit[nx][ny]) {
                    continue;
                }

                visit[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        return false;
    }

private:
    vector<vector<int>> directs;
};
