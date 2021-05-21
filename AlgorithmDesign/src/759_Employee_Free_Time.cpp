/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

        /**
         * https://leetcode.com/problems/employee-free-time/
         *
         * TC: O(NlogN)
         * SC: O(N)
         *
         *                |------------|
         *          |---|
         *          |-|     |-|
         *          -----------------------
         *          1 2 3 4 5 6 7 8 9 10
         *
         * count: 0 2 1 0 1 2 1 1 1 1 1
         *              | |
         *              |_| a free slot shared by everyone
         *
         */

        vector<pair<int, char>> events;

        for (const auto& person : schedule) {
            for (const auto& period : person) {
                events.push_back({period.start, BGN});
                events.push_back({period.end, END});
            }
        }
        sort(events.begin(), events.end());

        vector<Interval> ans;
        int count = 0, bgn = -1;

        for (const auto& event : events) {
            if (event.second == BGN) {
                ++count;
                // Reach the end of a shared free slot.
                if (count == 1 && bgn != -1 && event.first > bgn) {
                    ans.emplace_back(bgn, event.first);
                    bgn = -1;
                }
            } else {
                --count;
                // Reach the start of a shared free slot.
                if (count == 0) {
                    bgn = event.first;
                }
            }
        }

        return ans;
    }

private:
    enum {
        END = 0,
        BGN
    };
};