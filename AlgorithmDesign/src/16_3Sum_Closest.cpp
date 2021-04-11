class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        /**
         * https://leetcode.com/problems/3sum-closest/
         *
         * TC: O(N ^ 2)
         * SC: O(1)
         */

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0, opt_diff = INT_MAX;

        for (int i = 0 ; i < n - 2 ; ++i) {
            target -= nums[i];
            int l = i + 1, r = n - 1;

            while (l < r) {
                int diff = nums[l] + nums[r] - target;
                int abs_diff = abs(diff);

                if (abs_diff < opt_diff) {
                    opt_diff = abs_diff;
                    ans = nums[l] + nums[r] + nums[i];
                }

                if (diff < 0) {
                    ++l;
                } else {
                    --r;
                }
            }

            target += nums[i];
        }

        return ans;
    }
};