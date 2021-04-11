class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {

        /**
         * https://leetcode.com/problems/3sum-smaller/
         *
         * TC: O(N ^ 2)
         * SC: O(1)
         */

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 0 ; i < n ; ++i) {
            target -= nums[i];

            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] >= target) {
                    --r;
                } else {
                    ans += r - l;
                    ++l;
                }
            }

            target += nums[i];
        }

        return ans;
    }
};