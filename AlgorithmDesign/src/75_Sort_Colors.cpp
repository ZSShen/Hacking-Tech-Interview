class Solution {
public:
    void sortColors(vector<int>& nums) {

        /**
         * https://leetcode.com/problems/sort-colors/
         *
         * TC: O(N)
         * SC: O(1)
         *
         * We use 3 pointers to track the elements:
         *
         *  1. The "one" pointer guides the scanning procedure.
         *  2. The "zero" pointer points to tail of the consecutive zeros, which
         *     are shifted to the left hand side of the array.
         *  3. The "two" pointer points to the head of the consecutive twos,
         *     which are shifted to the right hand side of the array.
         *
         *       zero     two
         *          |     |
         *          v     v
         *  0 0 0 0 1 1 1 1 2 2 2 2
         */

        int n = nums.size();
        int zero = -1, one = 0, two = n;

        while (one < two) {
            if (nums[one] == 1) {
                ++one;
                continue;
            }

            if (nums[one] == 0) {
                swap(nums[++zero], nums[one++]);
            } else {
                swap(nums[--two], nums[one]);
            }
        }
    }
};