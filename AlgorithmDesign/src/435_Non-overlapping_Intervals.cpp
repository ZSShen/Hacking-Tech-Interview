class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // TC: O(nlogn)
        // SC: O(n)

        int n = intervals.size();
        if (n <= 1) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(),
            [] (const auto& l, const auto& r) {
                return l[1] < r[1];
            }
        );

        int ans = 0;
        int pivot = intervals[0][1];

        for (int i = 1 ; i < n ; ++i) {
            if (intervals[i][0] >= pivot) {
                pivot = intervals[i][1];
            } else {
                ++ans;
            }
        }

        return ans;
    }
};