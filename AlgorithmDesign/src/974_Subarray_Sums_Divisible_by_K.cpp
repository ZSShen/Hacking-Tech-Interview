class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {

        /**
         * https://leetcode.com/problems/subarray-sums-divisible-by-k/
         *
         * TC: O(n)
         * SC: O(n)
         *
         *  A: 4, 5, 0, -2, -3, 1
         *  K: 5
         *
         *  G[0]: 1
         *  G[1]: 0
         *  G[2]: 1
         *  G[3]: 0
         *  G[4]: 4
         *
         *  Prefixes: 4, 9, 9, 7, 4, 5
         *  Count   : 0, 1, 3, 3, 6, 7
         */

        vector<int> map(K);
        map[0] = 1;

        int ans = 0;
        int prefix = 0;
        for (int num : A) {
            prefix += num;
            int r = prefix % K;
            if (r < 0) {
                r += K;
            }
            ans += map[r];
            ++map[r];
        }

        return ans;
    }
};