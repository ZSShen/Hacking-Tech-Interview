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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        /**
         * https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
         *
         * TC: O(N)
         * SC: O(H)
         */

        auto res = runPostOrder(root);
        return res.first;
    }

private:
    pair<TreeNode*, int> runPostOrder(TreeNode* root) {

        if (!root) {
            return {nullptr, -1};
        }

        auto l = runPostOrder(root->left);
        auto r = runPostOrder(root->right);

        if (l.second == r.second) {
            return {root, l.second + 1};
        }

        if (l.second > r.second) {
            return {l.first, l.second + 1};
        }
        return {r.first, r.second + 1};
    }
};