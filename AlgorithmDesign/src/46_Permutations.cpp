class Solution {
public:
    vector<vector<int>> permute(vector<int>& cands) {

        /**
         * https://leetcode.com/problems/permutations/
         *
         * TC: O(N * N!)
         * SC: O(N) not include answer vector
         */

        int n = cands.size();
        vector<bool> visit(n);
        vector<int> config;
        vector<vector<int>> ans;

        helper(cands, 0, n, visit, config, ans);
        return ans;
    }

private:
    void helper(
            const vector<int>& cands, int c, int n,
            vector<bool>& visit,
            vector<int>& config,
            vector<vector<int>>& ans) {

        if (c == n) {
            ans.push_back(config);
            return;
        }

        for (int i = 0 ; i < n ; ++i) {
            if (visit[i]) {
                continue;
            }

            visit[i] = true;
            config.push_back(cands[i]);
            helper(cands, c + 1, n, visit, config, ans);
            config.pop_back();
            visit[i] = false;
        }
    }
};