class Solution {
public:
    Solution()
        : directs({{-1, 0, 'u'}, {0, 1, 'r'}, {0, -1, 'l'}, {1, 0, 'd'}})
    { }

    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {

        /**
         *  TC: O(m * n * (m + n))
         *  SC: O(m * n)
         */

        int m = maze.size();
        int n = maze[0].size();

        string config, opt_config;
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        dfs(ball[0], ball[1], hole[0], hole[1], m, n,
            maze, cost, 0, config, opt_config);

        return opt_config.length() > 0 ? opt_config : "impossible";
    }

private:
    vector<vector<int>> directs;

    void dfs(
            int x, int y, int dx, int dy, int m, int n,
            const vector<vector<int>>& maze,
            vector<vector<int>>& cost,
            int dist, string& config, string& opt_config) {

        for (const auto& d : directs) {
            int nx = x + d[0];
            int ny = y + d[1];

            // Start rolling the ball.
            while ((nx >= 0 && ny >= 0 && nx < m && ny < n) &&
                    maze[nx][ny] == 0 &&
                    !(nx == dx && ny == dy)) {
                nx += d[0];
                ny += d[1];
            }

            // Bounce back if hitting a wall.
            if (!(nx == dx && ny == dy)) {
                nx -= d[0];
                ny -= d[1];
            }

            // Update the cost.
            int delta = abs(nx - x) + abs(ny - y);
            if (delta == 0) {
                continue;
            }

            int new_dist = dist + delta;
            if (new_dist > cost[nx][ny]) {
                continue;
            }
            cost[nx][ny] = new_dist;

            config.push_back(d[2]);

            // Enter the hole.
            if (nx == dx && ny == dy) {
                opt_config = config;
            } else {
                dfs(nx, ny, dx, dy, m, n,
                    maze, cost, new_dist, config, opt_config);
            }

            config.pop_back();
        }
    }
};