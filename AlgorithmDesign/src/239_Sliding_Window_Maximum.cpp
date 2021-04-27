class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        /**
         * https://leetcode.com/problems/sliding-window-maximum/
         *
         * TC: O(N)
         * SC: O(N)
         */

        int n = nums.size();

        deque<int> q;
        for (int i = 0 ; i < k ; ++i) {
            insert(q, nums, i);
        }

        vector<int> ans;
        ans.emplace_back(nums[q.front()]);

        for (int i = k ; i < n ; ++i) {
            insert(q, nums, i);
            remove(q, i - k);
            ans.emplace_back(nums[q.front()]);
        }

        return ans;
    }

private:
    void insert(deque<int>& q, vector<int>& nums, int index) {
        int num = nums[index];
        while (!q.empty() && num > nums[q.back()]) {
            q.pop_back();
        }
        q.emplace_back(index);
    }

    void remove(deque<int>& q, int index) {
        if (q.front() == index) {
            q.pop_front();
        }
    }
};