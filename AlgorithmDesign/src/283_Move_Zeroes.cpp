class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        /**
         * https://leetcode.com/problems/move-zeroes/
         *
         * TC: O(N)
         * SC: O(1)
         */

        int l = -1;
        int n = nums.size();
        for (int r = 0 ; r < n ; ++r) {
            if (nums[r] != 0) {
                swap(nums[++l], nums[r]);
            }
        }
    }
};