class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {

        /**
         *  dp[i]: The length of the longest path starting from the ith bar.
         *
         *  dp[i] = MAX { 1 + dp[j] | the jth bar is reachable from the ith bar. }
         *
         *  TC: O(nd)
         *  SC: O(n)
         */

        int n = arr.size();

        vector<int> dp(n);
        int ans = 1;
        for (int i = 0 ; i < n ; ++i) {
            ans = max(ans, topDown(i, n, d, arr, dp));
        }
        return ans;
    }

private:
    int topDown(
            int start, int n, int d,
            const vector<int>& arr,
            vector<int>& dp) {

        if (dp[start] > 0) {
            return dp[start];
        }

        int opt = 1;

        // Check the left-hand side.
        int bnd = max(start - d, 0);
        for (int i = start -1 ; i >= bnd ; --i) {
            if (arr[i] >= arr[start]) {
                break;
            }
            opt = max(opt, 1 + topDown(i, n, d, arr, dp));
        }

        // Check the right-hand side.
        bnd = min(start + d, n - 1);
        for (int i = start + 1 ; i <= bnd ; ++i) {
            if (arr[i] >= arr[start]) {
                break;
            }
            opt = max(opt, 1 + topDown(i, n, d, arr, dp));
        }

        return dp[start] = opt;
    }
};
