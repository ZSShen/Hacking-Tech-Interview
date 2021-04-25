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
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        /**
         * https://leetcode.com/problems/validate-binary-search-tree/
         *
         * TC: O(N)
         * SC: O(H)
         */

        return helper(root, nullptr, nullptr);
    }

private:
    bool helper(TreeNode *root, TreeNode *lo, TreeNode *hi) {

        if (!root) {
            return true;
        }
        if (lo && root->val <= lo->val) {
            return false;
        }
        if (hi && root->val >= hi->val) {
            return false;
        }

        if (!helper(root->left, lo, root)) {
            return false;
        }
        return helper(root->right, root, hi);
    }
};