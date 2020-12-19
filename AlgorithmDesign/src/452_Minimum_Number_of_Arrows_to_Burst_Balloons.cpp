class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        /*
            [[10,16],[2,8],[1,6],[7,12]]

                     ------------

           --------
               ----------
                            --------
            -----------------------------
            1  2  6  7  8  10  12  16

            Must sort the ballons using the ending point.

            The counter example for sorting based on starting point.

                a        b
              -----    -----
                     c
            -------------------

            sorting based on starting point:
                        c -> a -> b,  1 arrow (wrong)

            sorting based on endint point:
                        a -> b -> c,  2 arrows (correct)

        */

        int n = points.size();
        if (n == 0) {
            return 0;
        }

        sort(points.begin(), points.end(),
             [](const auto& l, const auto& r) {
            return l[1] < r[1];
        });

        int ans = 1;
        int last = points[0][1];

        for (int i = 1 ; i < n ; ++i) {
            if (points[i][0] <= last) {
                continue;
            }

            ++ans;
            last = points[i][1];
        }

        return ans;
    }
};