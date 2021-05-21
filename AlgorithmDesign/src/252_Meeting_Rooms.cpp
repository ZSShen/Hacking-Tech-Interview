class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {

        /**
         * https://leetcode.com/problems/meeting-rooms/
         *
         * TC: O(NlogN)
         * SC: O(1)
         */

        int n = intervals.size();
        if (n == 0) {
            return true;
        }

        sort(intervals.begin(), intervals.end());

        for (int i = 1 ; i < n ; ++i) {
            if (intervals[i - 1][1] > intervals[i][0]) {
                return false;
            }
        }
        return true;
    }
};