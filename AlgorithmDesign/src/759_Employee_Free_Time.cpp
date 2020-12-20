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
            TC: O(nlogn)
            SC: O(n)

                      |------------|
                |---|

                |-|     |-|
                -------------------------
                1 2 3 4 5 6 7 8 9 10

         cnt: 0 2 1 0 1 2 1 1 1 1 1
                    | |
                    |_|
                    free slot.

        */

        using Point = pair<int, char>;
        vector<Point> points;

        for (const auto& s : schedule) {
            for (const auto& interval : s) {
                points.push_back({interval.start, BGN});
                points.push_back({interval.end, END});
            }
        }

        sort(points.begin(), points.end(),
            [] (const auto& l, const auto& r) {
                if (l.first == r.first) {
                    return l.second < r.second;
                }
                return l.first < r.first;
            }
        );

        vector<Interval> ans;
        int b = -1;
        int count = 0;

        for (const auto& p : points) {
            if (p.second == BGN) {
                ++count;
                // Reach the ending point of a shared free slot.
                if (count == 1 && b != -1 && p.first > b) {
                    ans.push_back({b, p.first});
                    b = -1;
                }
            } else {
                --count;
                // Reach the beginning point of a shared free slot.
                if (count == 0) {
                    b = p.first;
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