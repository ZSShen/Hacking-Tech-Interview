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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        /**
         * https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
         *
         * TC: O(N + M)
         * SC: O(Hn + Hm)
         */

        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;

        populate(stk1, root1);
        populate(stk2, root2);

        vector<int> ans;

        while (!stk1.empty() && !stk2.empty()) {

            auto node1 = stk1.top();
            auto node2 = stk2.top();

            int e1 = node1->val;
            int e2 = node2->val;

            if (e1 < e2) {
                ans.emplace_back(e1);
                stk1.pop();
                populate(stk1, node1->right);
            } else {
                ans.emplace_back(e2);
                stk2.pop();
                populate(stk2, node2->right);
            }
        }

        while (!stk1.empty()) {
            auto node = stk1.top();
            ans.emplace_back(node->val);
            stk1.pop();
            populate(stk1, node->right);
        }
        while (!stk2.empty()) {
            auto node = stk2.top();
            ans.emplace_back(node->val);
            stk2.pop();
            populate(stk2, node->right);
        }

        return ans;
    }

private:
    void populate(stack<TreeNode*>& stack, TreeNode* root) {
        while (root) {
            stack.emplace(root);
            root = root->left;
        }
    }
};