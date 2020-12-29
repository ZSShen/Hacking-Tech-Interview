class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        /**
         * TC: O(n)
         * SC: O(n)
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