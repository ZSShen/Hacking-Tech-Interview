class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {

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