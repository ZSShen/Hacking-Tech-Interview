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
    vector<vector<int>> verticalOrder(TreeNode* root) {

        /**
         * https://leetcode.com/problems/binary-tree-vertical-order-traversal/
         *
         * TC: O(N)
         * SC: O(N)
         */

        if (!root) {
            return {};
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        unordered_map<int, vector<int>> map;
        int min_col = INT_MAX, max_col = INT_MIN;

        while (!q.empty()) {
            auto pair = q.front();
            q.pop();

            auto node = pair.first;
            int col = pair.second;

            map[col].emplace_back(node->val);

            min_col = min(min_col, col);
            max_col = max(max_col, col);

            if (node->left) {
                q.push({node->left, col - 1});
            }
            if (node->right) {
                q.push({node->right, col + 1});
            }
        }

        vector<vector<int>> ans;
        for (int i = min_col ; i <= max_col ; ++i) {
            if (map.count(i) == 1) {
                ans.emplace_back(move(map[i]));
            }
        }
        return ans;
    }
};