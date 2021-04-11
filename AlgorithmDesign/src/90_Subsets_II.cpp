class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& cands) {

        /**
         * https://leetcode.com/problems/subsets-ii/
         *
         * TC: O(N * 2^N)
         * SC: O(N) not include answer
         */

        vector<int> config;
        vector<vector<int>> ans;

        sort(cands.begin(), cands.end());

        int n = cands.size();
        for (int i = 0 ; i <= n ; ++i) {
            helper(cands, 0, n, 0, i, config, ans);
        }

        return ans;
    }

private:
    void helper(
            const vector<int>& cands,
            int bgn, int end, int c, int n,
            vector<int>& config,
            vector<vector<int>>& ans) {

        if (c == n) {
            ans.push_back(config);
            return;
        }

        for (int i = bgn ; i < end ; ++i) {

            if (i > bgn && cands[i] == cands[i - 1]) {
                continue;
            }

            config.emplace_back(cands[i]);
            helper(cands, i + 1, end, c + 1, n, config, ans);
            config.pop_back();
        }
    }
};