class Solution {
public:
    int maxProduct(vector<int>& nums) {

        /**
         * https://leetcode.com/problems/maximum-product-subarray/
         *
         * TC: O(n)
         * TC: O(1)
         *
         *
         *    | min_sofar * num
         *    | max_sofar * num
         *    | num
         *
         *               [2, 3, -2, -4]
         *
         * min_sofar = 1  2  6 -12  -4
         * max_sofar = 1  2  6  -2  48
         *                           ^
         *
         *               [-2, 0, -1]
         *
         * min_sofar = 1  -2  0  -1
         * max_sofar = 1  -2  0   0
         *                    ^
         *
         *               [-2, 0, -1, 9, 0]
         *
         * min_sofar = 1  -2  0  -1 -9  0
         * max_sofar = 1  -2  0   0  9  0
         *                           ^
         */

        int min_sofar = 1, max_sofar = 1;
        int ans = nums[0];

        for (int num : nums) {
            int min_curr = min(min(num, min_sofar * num), max_sofar * num);
            int max_curr = max(max(num, min_sofar * num), max_sofar * num);

            ans = max(ans, max_curr);
            min_sofar = min_curr;
            max_sofar = max_curr;
        }

        return ans;
    }
};