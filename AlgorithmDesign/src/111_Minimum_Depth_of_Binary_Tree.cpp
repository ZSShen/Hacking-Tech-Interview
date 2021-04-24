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
    int minDepth(TreeNode* root) {

        /**
         * https://leetcode.com/problems/minimum-depth-of-binary-tree/
         *
         * TC: O(N)
         * SC: O(logN)
         */

        int ans = INT_MAX;
        helper(root, 0, ans);
        return ans < INT_MAX ? ans : 0;
    }

private:
    void helper(TreeNode* root, int depth, int& ans) {

        if (!root) {
            return;
        }

        ++depth;

        if (!root->left && !root->right) {
            ans = min(ans, depth);
        }

        helper(root->left, depth, ans);
        helper(root->right, depth, ans);
    }
};