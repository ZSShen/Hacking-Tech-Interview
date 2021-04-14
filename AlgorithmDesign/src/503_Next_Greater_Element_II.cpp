class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        /**
         * https://leetcode.com/problems/next-greater-element-ii/
         *
         * TC: O(N)
         * SC: O(N)
         */

        int n = nums.size();
        int nn = n << 1;

        // Maintain a monotonous decreasing stack.
        stack<int> stk;
        vector<int> ans(n, -1);

        for (int i = 0 ; i < nn ; ++i) {
            int j = i % n;
            int num = nums[j];

            while (!stk.empty() && num > nums[stk.top()]) {
                ans[stk.top()] = num;
                stk.pop();
            }

            stk.emplace(j);
        }

        return ans;
    }
};