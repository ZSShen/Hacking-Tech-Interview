class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> left(n), right(n);
        vector<int> left_index(n), right_index(n);

        int p = 0, s = 0;
        for (int i = 0, j = n - 1 ; i < k ; ++i, --j) {
            p += nums[i];
            s += nums[j];
        }

        left[k - 1] = p;
        right[n - k] = s;
        right_index[n - k] = n - k;

        for (int i = k, j = n - k - 1 ; i < n - 2 * k ; ++i, --j) {
            p = p - nums[i - k] + nums[i];
            left[i] = left[i - 1];
            left_index[i] = left_index[i - 1];

            if (p > left[i]) {
                left[i] = p;
                left_index[i] = i - k + 1;
            }

            s = s - nums[j + k] + nums[j];
            right[j] = right[j + 1];
            right_index[j] = right_index[j + 1];

            if (s >= right[j]) {
                right[j] = s;
                right_index[j] = j;
            }
        }

        int a = -1, b = -1, c = -1;
        int opt = INT_MIN;

        int window = 0;
        for (int i = k ; i < 2 * k ; ++i) {
            window += nums[i];
        }

        for (int i = k ; i < n - k ; ++i) {
            int sum = window + left[i - 1] + right[i + k];
            if (sum > opt) {
                opt = sum;
                a = left_index[i - 1];
                b = i;
                c = right_index[i + k];
            }
            window = window - nums[i] + nums[i + k];
        }

        return {a, b, c};
    }
};
