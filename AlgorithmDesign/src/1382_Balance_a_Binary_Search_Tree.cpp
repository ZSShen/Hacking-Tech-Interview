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
    TreeNode* balanceBST(TreeNode* root) {

        /**
         * https://leetcode.com/problems/balance-a-binary-search-tree/
         *
         * TC: O(N)
         * SC: O(N)
         */

        vector<int> nums;
        collectNodes(root, nums);
        return buildBalancedBST(nums, 0, nums.size() - 1);
    }

private:
    void collectNodes(
            TreeNode* curr, vector<int>& nums) {

        if (!curr) {
            return;
        }

        collectNodes(curr->left, nums);
        nums.emplace_back(curr->val);
        collectNodes(curr->right, nums);
    }

    TreeNode* buildBalancedBST(
            vector<int>& nums, int l, int r) {

        if (l > r) {
            return nullptr;
        }
        if (l == r) {
            return new TreeNode(nums[l]);
        }

        int m = (l + r) / 2;
        auto node = new TreeNode(nums[m]);
        node->left = buildBalancedBST(nums, l, m - 1);
        node->right = buildBalancedBST(nums, m + 1, r);
        return node;
    }
};