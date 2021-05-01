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
    int sumNumbers(TreeNode* root) {

        /**
         * https://leetcode.com/problems/sum-root-to-leaf-numbers/
         *
         * TC: O(N)
         * SC: O(H)
         */

        int prefix = 0, ans = 0;
        runPreOrder(root, prefix, ans);
        return ans;
    }

private:
    void runPreOrder(TreeNode* root, int prefix, int& ans) {

        if (!root) {
            return;
        }

        prefix = prefix * 10 + root->val;

        if (!root->left && !root->right) {
            ans += prefix;
        }

        runPreOrder(root->left, prefix, ans);
        runPreOrder(root->right, prefix, ans);
    }
};