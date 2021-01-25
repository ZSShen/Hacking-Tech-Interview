class SparseVector {
public:

    SparseVector(vector<int> &nums) {

        int n = nums.size();
        for (int i = 0 ; i < n ; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            vec.push_back({i, nums[i]});
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& rhs) {

        int ans = 0;
        int ni = vec.size(), nj = rhs.vec.size();
        int i = 0, j = 0;

        while (i < ni && j < nj) {
            if (vec[i].first == rhs.vec[j].first) {
                ans += vec[i++].second * rhs.vec[j++].second;
            } else {
                if (vec[i].first < rhs.vec[j].first) {
                    ++i;
                } else {
                    ++j;
                }
            }
        }

        return ans;
    }

private:
    vector<pair<int, int>> vec;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);