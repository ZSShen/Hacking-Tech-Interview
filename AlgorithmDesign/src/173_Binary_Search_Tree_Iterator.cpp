/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {

        /**
         * https://leetcode.com/problems/binary-search-tree-iterator
         *
         * TC: O(1) amortized constant time
         * SC: O(H) on average, O(N) worst case for skew binary tree.
         */

        while (root) {
            stack.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {

        auto top = stack.top();
        stack.pop();

        int val = top->val;

        top = top->right;
        while (top) {
            stack.push(top);
            top = top->left;
        }

        return val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {

        return !stack.empty();
    }

private:
    std::stack<TreeNode*> stack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */