class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        /**
         * https://leetcode.com/problems/sliding-window-median/
         *
         * TC: O(NlogK)
         * SC: O(K)
         */

        multiset<int, greater<int>> max_q;
        multiset<int, less<int>> min_q;

        int c = 0;
        int n = nums.size();

        vector<double> ans;

        for (int i = 0 ; i < n ; ++i) {
            insert(max_q, min_q, nums[i]);
            ++c;

            if (c > k) {
                remove(max_q, min_q, nums[i - k]);
                --c;
            }

            rebalance(max_q, min_q);

            if (c == k) {
                ans.emplace_back(query(max_q, min_q));
            }
        }

        return ans;
    }

private:
    void insert(
            multiset<int, greater<int>>& max_q,
            multiset<int, less<int>>& min_q,
            int num) {

        if (max_q.empty()) {
            max_q.emplace(num);
            return;
        }

        int top = *(max_q.begin());
        if (num <= top) {
            max_q.emplace(num);
        } else {
            min_q.emplace(num);
        }
    }

    void remove(
            multiset<int, greater<int>>& max_q,
            multiset<int, less<int>>& min_q,
            int num) {

        auto it = max_q.find(num);
        if (it != max_q.end()) {
            max_q.erase(it);
            return;
        }

        it = min_q.find(num);
        min_q.erase(it);
    }

    void rebalance(
            multiset<int, greater<int>>& max_q,
            multiset<int, less<int>>& min_q) {

        int n_max = max_q.size();
        int n_min = min_q.size();

        if (n_max - n_min > 1) {
            auto it = max_q.begin();
            min_q.emplace(*it);
            max_q.erase(it);
        }
        if (n_min - n_max > 1) {
            auto it = min_q.begin();
            max_q.emplace(*it);
            min_q.erase(it);
        }
    }

    double query(
            multiset<int, greater<int>>& max_q,
            multiset<int, less<int>>& min_q) {

        int n_max = max_q.size();
        int n_min = min_q.size();

        if (n_max == n_min) {
            double a = *max_q.begin();
            double b = *min_q.begin();
            return (a + b) / 2;
        }

        return n_max > n_min ? *max_q.begin() : *min_q.begin();
    }
};