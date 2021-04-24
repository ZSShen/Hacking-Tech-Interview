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
    void flatten(TreeNode* root) {
        /**
         * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
         *
         * TC: O(N)
         * SC: O(N)
         *
            case 1.

                root

                return root


            case 2.

                root           root
                /       =>        \
               L                   L

               return last L


            case 3.

                root
                   \
                    R

                return last R


            case 4.

                root         root       root
                /  \    =>   /     =>      \
               L    R       L               L
                             \               \
                              R               R

                return last R
        */

        runPostOrder(root);
    }

private:
    TreeNode* runPostOrder(TreeNode* root) {

        if (!root) {
            return nullptr;
        }

        auto l = runPostOrder(root->left);
        auto r = runPostOrder(root->right);

        if (l) {
            l->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        if (r) {
            return r;
        }
        if (l) {
            return l;
        }
        return root;
    }
};