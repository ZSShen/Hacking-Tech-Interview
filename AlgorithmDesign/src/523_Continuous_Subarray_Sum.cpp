class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        /**
         * https://leetcode.com/problems/continuous-subarray-sum/
         *
         * TC: O(n)
         * SC: O(n)
         */

        unordered_map<int, int> map;
        map[0] = -1;

        int n = nums.size();
        int mod = 0;

        for (int i = 0 ; i < n ; ++i) {
            mod += nums[i];
            mod = (k != 0) ? mod % k : mod;

            if (map.count(mod) == 1) {
                if (i - map[mod] > 1) {
                    return true;
                }
            } else {
                map[mod] = i;
            }
        }

        return false;
    }
};