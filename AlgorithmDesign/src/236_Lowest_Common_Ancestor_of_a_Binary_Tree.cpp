/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        /**
         * TC: O(n)
         * SC: O(n) // Cost of making recursive calls.
         */

        if (!root || root == p || root == q) {
            return root;
        }

        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);

        if (l && r) {
            return root;
        }

        if (l) {
            return l;
        }
        return r;
    }
};