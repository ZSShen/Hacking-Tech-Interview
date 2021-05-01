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
    int maxPathSum(TreeNode* root) {

        /**
         * https://leetcode.com/problems/binary-tree-maximum-path-sum/
         *
         * TC: O(N)
         * SC: O(H)
         */

        int opt = INT_MIN;
        runPostOrder(root, opt);
        return opt;
    }

private:
    int runPostOrder(TreeNode* root, int& opt) {

        if (!root) {
            return 0;
        }

        int l = runPostOrder(root->left, opt);
        int r = runPostOrder(root->right, opt);

        opt = max(opt, root->val);
        opt = max(opt, root->val + r);
        opt = max(opt, root->val + l);
        opt = max(opt, root->val + r + l);

        return max(root->val, max(root->val + l, root->val + r));
    }
};