class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {

        /**
         * TC: O(n)
         * SC: O(n)
         */

        int n = A.size();

        vector<int> left_m(n, INT_MIN);
        vector<int> right_m(n, INT_MIN);
        vector<int> left_l(n, INT_MIN);
        vector<int> right_l(n, INT_MIN);

        int p = 0;
        int s = 0;

        // Calculate the subarrays with size L.
        for (int i = 0, j = n - 1 ; i < L ; ++i, --j) {
            p += A[i];
            s += A[j];
        }
        left_l[L - 1] = p;
        right_l[n - L] = s;

        for (int i = L, j = n - L - 1 ; i < n ; ++i, --j) {
            p += A[i] - A[i - L];
            s += A[j] - A[j + L];
            left_l[i] = max(left_l[i - 1], p);
            right_l[j] = max(right_l[j + 1], s);
        }

        // Calculate the subarrays with size M.
        p = 0;
        s = 0;
        for (int i = 0, j = n - 1 ; i < M ; ++i, --j) {
            p += A[i];
            s += A[j];
        }
        left_m[M - 1] = p;
        right_m[n - M] = s;

        for (int i = M, j = n - M - 1 ; i < n ; ++i, --j) {
            p += A[i] - A[i - M];
            s += A[j] - A[j + M];
            left_m[i] = max(left_m[i - 1], p);
            right_m[j] = max(right_m[j + 1], s);
        }

        int ans = 0;
        for (int i = 0 ; i < n - 1 ; ++i) {
            if (left_l[i] != INT_MIN && right_m[i + 1] != INT_MIN) {
                ans = max(ans, left_l[i] + right_m[i + 1]);
            }
            if (left_m[i] != INT_MIN && right_l[i + 1] != INT_MIN) {
                ans = max(ans, left_m[i] + right_l[i + 1]);
            }
        }
        return ans;
    }
};