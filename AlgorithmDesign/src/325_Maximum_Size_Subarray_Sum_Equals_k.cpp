class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {

        /**
         * https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
         *
         * TC: O(n)
         * SC: O(n)
         *
         *   1  -1  5  -2  3
         *   1   0  5   3  6
         *
         *  -2  -1  2   1
         *  -2  -3  -1  0
         *
         *  HashTable(Key = Prefix Sum) = (Value = Index)
         */

        unordered_map<int, int> map;
        map[0] = -1;

        int n = nums.size();
        int prefix = 0;
        int ans = 0;

        for (int i = 0 ; i < n ; ++i) {
            prefix += nums[i];
            int target = prefix - k;

            if (map.count(target) == 1) {
                ans = max(ans, i - map[target]);
            }
            if (map.count(prefix) == 0) {
                map[prefix] = i;
            }
        }

        return ans;
    }
};