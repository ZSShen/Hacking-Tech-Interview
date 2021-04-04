class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        /**
         * https://leetcode.com/problems/subarray-sum-equals-k/
         *
         * TC: O(n)
         * SC: O(n)
         *
         *  sum(i, j) = prefix(j) -  prefix(i - 1) = k
         *      => prefix(i - 1) = prefix(j) - k
         */

        unordered_map<int, int> freq;
        freq[0] = 1;

        int ans = 0;
        int prefix = 0;

        for (int num : nums) {
            prefix += num;
            ans += freq[prefix - k];
            ++freq[prefix];
        }

        return ans;
    }
};