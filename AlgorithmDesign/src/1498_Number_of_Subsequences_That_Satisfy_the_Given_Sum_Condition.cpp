class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        long mod = 1e9 + 7;
        int n = nums.size();
        vector<int> pow(n, 1);

        for (int i = 1 ; i < n ; ++i) {
            pow[i] = pow[i - 1] * 2 % mod;
        }

        int l = 0, r = n - 1;
        long ans = 0;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans += pow[r - l] % mod;
                ++l;
            } else {
                --r;
            }
        }

        return ans % mod;
    }
};