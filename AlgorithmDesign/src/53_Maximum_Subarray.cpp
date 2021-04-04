class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        /**
         * https://leetcode.com/problems/maximum-subarray/
         *
         * TC: O(n)
         * SC: O(1)
         */

        int ans = nums[0];
        int sum = 0;

        for (int num : nums) {
            sum += num;
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }

        return ans;
    }
};