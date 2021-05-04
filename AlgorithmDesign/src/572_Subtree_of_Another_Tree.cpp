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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        /**
         * https://leetcode.com/problems/subtree-of-another-tree/
         *
         * TC: O(N * M)
         * SC: O(M + N)
         */

        return findRoot(root, subRoot);
    }

private:
    bool findRoot(TreeNode* root, TreeNode* sub_root) {

        if (!root) {
            return false;
        }

        if (root->val == sub_root->val) {
            bool res = matchStructure(root, sub_root);
            if (res) {
                return true;
            }
        }

        if (findRoot(root->left, sub_root)) {
            return true;
        }
        return findRoot(root->right, sub_root);
    }

    bool matchStructure(TreeNode* root, TreeNode* sub_root) {

        if (!root || !sub_root) {
            return root == sub_root;
        }

        if (root->val != sub_root->val) {
            return false;
        }

        bool res = matchStructure(root->left, sub_root->left);
        if (!res) {
            return false;
        }
        return matchStructure(root->right, sub_root->right);
    }
};