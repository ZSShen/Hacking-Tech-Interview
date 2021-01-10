class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /**
         *   left partition:
         *   left[i] = prices[i] - lowest_buying
         *
         *   right partition:
         *   right[i] = highest_selling - prices[i]
         */

        int n = prices.size();

        vector<int> left(n);
        vector<int> right(n);

        int buy = prices[0];
        int sell = prices[n - 1];

        for (int i = 1, j = n - 2 ; i < n ; ++i, --j) {
            int p = prices[i];
            left[i] = max(left[i - 1], p - buy);
            buy = min(buy, p);

            p = prices[j];
            right[j] = max(right[j + 1], sell - p);
            sell = max(sell, p);
        }

        int ans = 0;
        for (int i = 0 ; i < n ; ++i) {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};