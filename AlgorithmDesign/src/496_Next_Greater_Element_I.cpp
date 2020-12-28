class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        /**
         * TC: O(n)
         * SC: O(n)
         */

        unordered_map<int, int> map;

        // Maintain a monotonous decreasing stack.
        stack<int> stk;
        for (int num : nums2) {
            while (!stk.empty() && num > stk.top()) {
                map[stk.top()] = num;
                stk.pop();
            }
            stk.emplace(num);
        }

        vector<int> ans;
        for (int num : nums1) {
            int next = (map.count(num) == 1) ? map[num] : -1;
            ans.emplace_back(next);
        }
        return ans;
    }
};