class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {

        /**
               -------  -------   ------

            ------     -----

            ------------------------------
            0 10 15 50 60 70 120 140 210


            (s1, e1)  (s2, e2)

            max(s1, s2) < min(e1, e2)
            => overlap

        */

        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int n1 = slots1.size();
        int n2 = slots2.size();
        int i = 0;
        int j = 0;

        while (i < n1 && j < n2) {
            int s1 = slots1[i][0];
            int e1 = slots1[i][1];
            int s2 = slots2[j][0];
            int e2 = slots2[j][1];

            int b = max(s1, s2);
            int e = min(e1, e2);

            if (b < e) {
                if (e - b >= duration) {
                    return {b, b + duration};
                }
            }

            if (e1 < e2) {
                ++i;
            } else {
                ++j;
            }
        }

        return {};
    }
};