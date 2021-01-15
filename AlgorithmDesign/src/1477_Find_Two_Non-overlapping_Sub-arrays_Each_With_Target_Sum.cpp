class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        /**
         *  sum(i, j) = prefix(j) - prefix(i - 1) = target
         *              ^^^^^^^^^
         *                  p
         *
         *  => p - target = prefix(i - 1)
         *
         *  TC: O(n)
         *  SC: O(n)
         */
        int n = arr.size();

        vector<int> left(n, INT_MAX), right(n, INT_MAX);
        unordered_map<int, int> prefix, suffix;
        prefix[0] = -1;
        suffix[0] = n;

        int p = 0, s = 0;

        for (int i = 0, j = n - 1 ; i < n ; ++i, --j) {

            if (i > 0) {
                left[i] = left[i - 1];
                right[j] = right[j + 1];
            }

            p += arr[i];
            int t = p - target;
            if (prefix.count(t) == 1) {
                left[i] = min(left[i], i - prefix[t]);
            }

            s += arr[j];
            t = s - target;
            if (suffix.count(t) == 1) {
                right[j] = min(right[j], suffix[t] - j);
            }

            prefix[p] = i;
            suffix[s] = j;
        }

        int ans = INT_MAX;

        for (int i = 0 ; i < n - 1 ; ++i) {
            if (left[i] == INT_MAX || right[i + 1] == INT_MAX) {
                continue;
            }
            ans = min(ans, left[i] + right[i + 1]);
        }

        return ans < INT_MAX ? ans : -1;
    }
};