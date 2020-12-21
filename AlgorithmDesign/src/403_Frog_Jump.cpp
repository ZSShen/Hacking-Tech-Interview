class Solution {
public:
    bool canCross(vector<int>& stones) {

        /**
         * dp[i][j]: Whether we can reach the target if we are
         *           now standing at the ith stone and are ready
         *           to jump to the next neighbor by j units.
         *
         *  TC: O(n^2)
         *  TC: O(n^2)
         */

        int n = stones.size();

        // Edge case: [0, 2]
        if (stones[0] != 0 || stones[1] != 1) {
            return false;
        }

        unordered_map<int, int> map;
        for (int i = 0 ; i < n ; ++i) {
            map[stones[i]] = i;
        }

        vector<unordered_map<int, bool>> dp(n);
        return topDown(0, n, 0, 1, map, dp);
    }

private:
    bool topDown(
            int i, int n, int index, int k,
            unordered_map<int, int>& map,
            vector<unordered_map<int, bool>>& dp) {

        if (i == n - 1) {
            return true;
        }

        if (dp[i].count(k) == 1) {
            return dp[i][k];
        }

        // Try k - 1 unit.
        int next = index + k - 1;
        if (next > index && map.count(next) == 1) {
            bool res = topDown(map[next], n, next, k - 1, map, dp);
            if (res) {
                return dp[i][k] = true;
            }
        }

        // Try k unit.
        next = index + k;
        if (next > index && map.count(next) == 1) {
            bool res = topDown(map[next], n, next, k, map, dp);
            if (res) {
                return dp[i][k] = true;
            }
        }

        // Try k + 1 unit.
        next = index + k + 1;
        if (next > index && map.count(next) == 1) {
            bool res = topDown(map[next], n, next, k + 1, map, dp);
            if (res) {
                return dp[i][k] = true;
            }
        }

        return dp[i][k] = false;
    }
};