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
    TreeNode* str2tree(string s) {

        /**
         * https://leetcode.com/problems/construct-binary-tree-from-string/
         *
         * TC: O(N)
         * SC: O(N)
         */

        if (s.empty()) {
            return nullptr;
        }

        int offset = 0;
        return runPreOrder(s, offset, s.length());
    }

private:
    TreeNode* runPreOrder(const string& s, int& offset, int len) {

        int base = offset;
        while (offset < len && (s[offset] != '(' && s[offset] != ')')) {
            ++offset;
        }

        int num = stoi(s.substr(base, offset - base));
        auto root = new TreeNode(num);

        if (offset < len && s[offset] == '(') {
            root->left = runPreOrder(s, ++offset, len);
            ++offset;
        }

        if (offset < len && s[offset] == '(') {
            root->right = runPreOrder(s, ++offset, len);
            ++offset;
        }
        return root;
    }
};