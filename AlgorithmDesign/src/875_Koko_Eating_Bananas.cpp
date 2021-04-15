class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        /**
         * https://leetcode.com/problems/koko-eating-bananas/
         *
         * TC: O(log(M)) M is the size of the maximum pile.
         * SC: O(1)
         */

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (canFinish(piles, h, m)) {
                r = m;
            } else {
                l = m;
            }
        }

        return canFinish(piles, h, l) ? l : r;
    }

private:
    bool canFinish(
            const vector<int>& piles, int h, int k) {

        int count = 0;
        for (int p : piles) {
            count += ceil(static_cast<double>(p) / k);
        }
        return count <= h;
    }
};