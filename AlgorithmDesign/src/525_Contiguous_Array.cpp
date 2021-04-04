class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        /**
         * https://leetcode.com/problems/contiguous-array/
         *
         * TC: O(n)
         * SC: O(n)
         *
         * array(i, j) = prefix(j) - prefix(i - 1) = 0
         * => prefix(j) = prefix(i - 1)
         */

        int n = nums.size();

        unordered_map<int, int> map;
        map[0] = -1;

        int prefix = 0;
        int ans = 0;

        for (int i = 0 ; i < n ; ++i) {
            int num = nums[i];
            if (num == 1) {
                ++prefix;
            } else {
                --prefix;
            }

            if (map.count(prefix) == 1) {
                ans = max(ans, i - map[prefix]);
            } else {
                map[prefix] = i;
            }
        }

        return ans;
    }
};