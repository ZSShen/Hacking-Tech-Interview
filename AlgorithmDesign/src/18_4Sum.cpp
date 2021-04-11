class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        /**
         * https://leetcode.com/problems/4sum/
         *
         * TC: O(N ^ 3)
         * SC: O(1)
         */

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0 ; i < n - 3 ; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1 ; j < n - 2 ; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int l = j + 1, r = n - 1;
                helper(nums, i, j, l, r, target - nums[i] - nums[j], ans);
            }
        }

        return ans;
    }

private:
    void helper(
            const vector<int>& nums,
            int i, int j, int l, int r,
            int target,
            vector<vector<int>>& ans) {

        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) {
                ans.push_back({nums[i], nums[j], nums[l], nums[r]});

                while (++l < r && nums[l] == nums[l - 1]);
                while (l < --r && nums[r] == nums[r + 1]);
            } else {
                if (sum > target) {
                    while (l < --r && nums[r] == nums[r + 1]);
                } else {
                    while (++l < r && nums[l] == nums[l - 1]);
                }
            }
        }
    }
};