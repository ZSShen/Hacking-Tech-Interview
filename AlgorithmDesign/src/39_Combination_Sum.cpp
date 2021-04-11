class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cands, int target) {

        /**
         * https://leetcode.com/problems/combination-sum/
         *
         *  N: The number of candidates.
         *  T: The target value.
         *  M: The minimal value among the candidates.
         *
         *  TC: O(N ^ (T/M))
         *  SC: O(T/M)
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

            target -= cands[i];
            config.push_back(cands[i]);

            helper(cands, target, i, end, config, ans);

            config.pop_back();
            target += cands[i];
        }
    }
};