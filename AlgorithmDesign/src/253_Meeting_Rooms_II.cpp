class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        /**
         * https://leetcode.com/problems/meeting-rooms-ii/
         *
         * TC: O(NlogN)
         * SC: O(N)
         */

        vector<pair<int, char>> events;

        for (const auto& interval : intervals) {
            events.push_back({interval[0], BGN});
            events.push_back({interval[1], END});
        }

        sort(events.begin(), events.end());

        int ans = 0;
        int count = 0;
        for (const auto& event : events) {
            if (event.second == BGN) {
                ++count;
                ans = max(ans, count);
            } else {
                --count;
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