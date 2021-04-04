class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        /**
         * https://leetcode.com/problems/subarray-product-less-than-k/
         *
         * TC: O(n)
         * SC: O(1)
         */

        int n = nums.size();
        int l = 0;
        int count = 0;
        int prod = 1;

        for (int r = 0 ; r < n ; ++r) {
            prod *= nums[r];

            while (l <= r && prod >= k) {
                prod /= nums[l++];
            }

            count += r - l + 1;
        }

        return count;
    }
};