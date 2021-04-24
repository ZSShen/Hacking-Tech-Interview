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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (!root) {
            return {};
        }

        vector<vector<int>> ans;

        /**
         * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
         *
         *  TC: O(N)
         *  SC: O(N)
         *
         *  Odd-numbered layer:
         *      Check children from left to right.
         *
         *  Even-numbered layer:
         *      Check children from right to left.
         */

        stack<TreeNode*> stk;
        stk.emplace(root);

        int layer = 1;

        while (!stk.empty()) {
            stack<TreeNode*> temp;
            vector<int> line;

            while (!stk.empty()) {
                auto node = stk.top();
                stk.pop();
                line.emplace_back(node->val);

                if ((layer & 0x1) == 0x1) {
                    if (node->left) {
                        temp.emplace(node->left);
                    }
                    if (node->right) {
                        temp.emplace(node->right);
                    }
                } else {
                    if (node->right) {
                        temp.emplace(node->right);
                    }
                    if (node->left) {
                        temp.emplace(node->left);
                    }
                }
            }

            ans.emplace_back(move(line));
            stk = move(temp);
            ++layer;
        }

        return ans;
    }
};