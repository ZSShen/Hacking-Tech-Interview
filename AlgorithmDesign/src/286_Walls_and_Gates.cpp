class Solution {
public:
    Solution()
        : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    void wallsAndGates(vector<vector<int>>& rooms) {

        /**
         * https://leetcode.com/problems/walls-and-gates/
         *
         * TC: O(m * n)
         * SC: O(m * n)
         */

        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q;
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            ++dist;

            for (int i = 0 ; i < size ; ++i) {
                auto r = q.front();
                q.pop();

                int x = r.first;
                int y = r.second;

                for (const auto& d : directs) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (!(nx >= 0 && ny >= 0 && nx < m && ny < n) ||
                        rooms[nx][ny] != INF) {
                        continue;
                    }

                    rooms[nx][ny] = dist;
                    q.push({nx, ny});
                }
            }
        }
    }

private:
    vector<vector<int>> directs;

    static const int INF = 2147483647;
};