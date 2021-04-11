class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        /**
         * https://leetcode.com/problems/3sum/
         *
         * TC: O(N ^ 2)
         * SC: O(1)
         */

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0 ; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > 0) {
                break;
            }
            helper(nums, i, i + 1, n - 1, -nums[i], ans);
        }

        return ans;
    }

private:
    void helper(
            const vector<int>& nums,
            int i, int l, int r,
            int target,
            vector<vector<int>>& ans) {

        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) {
                ans.push_back({nums[i], nums[l], nums[r]});

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