/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct Record {
    int m = INT_MAX;
    int M = INT_MIN;
    int size = 0;
    bool is_bst = true;
};


class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {

        /**
         * https://leetcode.com/problems/largest-bst-subtree/
         *
         * TC: O(N)
         * SC: O(H)
         */

        int ans = 0;
        runPostOrder(root, ans);
        return ans;
    }

private:
    Record runPostOrder(TreeNode* root, int& ans) {

        if (!root) {
            return Record();
        }

        auto l = runPostOrder(root->left, ans);
        auto r = runPostOrder(root->right, ans);

        if (!l.is_bst || !r.is_bst) {
            Record record;
            record.is_bst = false;
            return record;
        }

        if (!(l.M < root->val && root->val < r.m)) {
            Record record;
            record.is_bst = false;
            return record;
        }

        Record record;
        record.size = l.size + r.size + 1;
        ans = max(ans, record.size);

        record.m = (l.size > 0) ? l.m : root->val;
        record.M = (r.size > 0) ? r.M : root->val;

        return record;
    }
};