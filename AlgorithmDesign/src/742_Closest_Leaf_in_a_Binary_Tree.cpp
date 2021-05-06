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

struct TNode {
    int val;
    TNode *left, *right, *parent;

    TNode(int val)
        : val(val), left(nullptr), right(nullptr), parent(nullptr)
    { }
};


class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {

        /**
         * https://leetcode.com/problems/closest-leaf-in-a-binary-tree/
         *
         * TC: O(N)
         * SC: O(N)
         */

        TNode* ref = nullptr;
        auto new_root = buildTree(root, nullptr, ref, k);

        int opt = INT_MAX;
        int ans = -1;
        dfs(ref, nullptr, 0, opt, ans);
        return ans;
    }

private:
    TNode* buildTree(TreeNode* curr, TNode* pred, TNode*& ref, int k) {

        if (!curr) {
            return nullptr;
        }

        auto root = new TNode(curr->val);
        root->left = buildTree(curr->left, root, ref, k);
        root->right = buildTree(curr->right, root, ref, k);
        root->parent = pred;

        if (curr->val == k) {
            ref = root;
        }
        return root;
    }

    void dfs(TNode* curr, TNode* pred, int dist, int& opt, int& ans) {

        if (!curr->left && !curr->right) {
            if (dist < opt) {
                opt = dist;
                ans = curr->val;
            }
            return;
        }

        if (curr->left && curr->left != pred) {
            dfs(curr->left, curr, dist + 1, opt, ans);
        }
        if (curr->right && curr->right != pred) {
            dfs(curr->right, curr, dist + 1, opt, ans);
        }
        if (curr->parent && curr->parent != pred) {
            dfs(curr->parent, curr, dist + 1, opt, ans);
        }
    }
};