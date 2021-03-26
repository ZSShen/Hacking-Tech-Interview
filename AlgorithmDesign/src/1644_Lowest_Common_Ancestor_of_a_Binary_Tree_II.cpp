/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Record {
    bool find_p = false;
    bool find_q = false;
    TreeNode* lca = nullptr;
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        /**
         * TC: O(n)
         * SC: O(n) // Cost of making recursive calls.
         */

        auto rtn = helper(root, p, q);
        return rtn.lca;
    }

private:
    Record helper(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root) {
            return Record();
        }

        auto l = helper(root->left, p, q);
        auto r = helper(root->right, p, q);

        if (l.lca) {
            return l;
        }
        if (r.lca) {
            return r;
        }

        Record rtn;
        rtn.find_p = l.find_p || r.find_p || root == p;
        rtn.find_q = l.find_q || r.find_q || root == q;

        if (rtn.find_p && rtn.find_q) {
            rtn.lca = root;
        }
        return rtn;
    }
};