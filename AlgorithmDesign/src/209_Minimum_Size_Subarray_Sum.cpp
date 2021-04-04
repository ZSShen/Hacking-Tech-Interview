class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        /**
         *  https://leetcode.com/problems/minimum-size-subarray-sum/
         *
         *  TC: O(n)
         *  SC: O(1)
         *
         *  Use 2 pointers, r and l, to scan the prefix sum array. In the
         *  procedure, r is the main pointer which controls the movement of
         *  our sliding window. When the subarray sum bounded by r and l,
         *  namely prefix[r] - prefix[l], is less than or eqaul to target,
         *  we try to adjust l so that we are able to get a smaller window
         *  that also fulfills the requirement.
         *
         *  Note: In real implementation, we may use a single varable to
         *        represent the prefix sum.
         *
         *    l
         *          r
         *  a b c d e f g h i
         *
         */

        int n = nums.size();

        int ans = INT_MAX;
        int window = 0;
        int l = 0;

        for (int r = 0 ; r < n ; ++r) {
            window += nums[r];

            while (window >= s && l <= r) {
                ans = min(ans, r - l + 1);
                window -= nums[l++];
            }
        }

        return (ans < INT_MAX) ? ans : 0;
    }
};