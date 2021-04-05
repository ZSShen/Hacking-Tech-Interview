class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        /**
         * https://leetcode.com/problems/product-of-array-except-self/
         *
         * TC: O(n)
         * SC: O(1)
         *
         *        a b c d e
         *      ----------->
         *
         *  ans   1 a a a a
         *            b b b
         *              c c
         *                d
         *
         *      <-----------
         *
         *  ans   b a a a a
         *        c c b b b
         *        d d d c c
         *        e e e e d
         *
         *  R     e e e e e
         *        d d d d
         *        c c c
         *        b b
         *        a
         */

        int n = nums.size();

        vector<int> ans(n);

        ans[0] = 1;
        for (int i = 1 ; i < n ; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int R = 1;
        for (int i = n - 1 ; i >= 0 ; --i) {
            ans[i] = ans[i] * R;
            R *= nums[i];
        }

        return ans;
    }
};