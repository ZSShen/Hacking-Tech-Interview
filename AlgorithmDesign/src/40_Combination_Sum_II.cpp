class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cands, int target) {

        /**
         * https://leetcode.com/problems/combination-sum-ii/
         *
         *  TC: O(2 ^ N)
         *  SC: O(N)
         */

        vector<int> config;
        vector<vector<int>> ans;

        sort(cands.begin(), cands.end());
        helper(cands, target, 0, cands.size(), config, ans);
        return ans;
    }

private:
    void helper(
        const vector<int>& cands, int target,
        int bgn, int end,
        vector<int>& config,
        vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(config);
            return;
        }

        for (int i = bgn ; i < end ; ++i) {
            if (cands[i] > target) {
                break;
            }

            if (i > bgn && cands[i] == cands[i - 1]) {
                continue;
            }

            target -= cands[i];
            config.push_back(cands[i]);

            helper(cands, target, i + 1, end, config, ans);

            config.pop_back();
            target += cands[i];
        }
    }
};