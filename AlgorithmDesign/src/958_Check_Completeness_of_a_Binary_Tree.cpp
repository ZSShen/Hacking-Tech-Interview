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
    bool isCompleteTree(TreeNode* root) {

        /**
         * https://leetcode.com/problems/check-completeness-of-a-binary-tree/
         *
         * TC: O(N)
         * SC: O(N)
         */

        queue<TreeNode*> q;
        q.emplace(root);
        bool last_node_visited = false;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            if (!node) {
                last_node_visited = true;
            } else {
                if (last_node_visited) {
                    return false;
                }

                q.emplace(node->left);
                q.emplace(node->right);
            }
        }

        return true;
    }
};