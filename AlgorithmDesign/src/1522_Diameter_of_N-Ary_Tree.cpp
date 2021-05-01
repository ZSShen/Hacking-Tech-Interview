/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int diameter(Node* root) {

        /**
         * https://leetcode.com/problems/diameter-of-n-ary-tree/
         *
         * TC: O(K*N) Assume n nodes and k is the average branch degree.
         * SC: O(H)
         */

        int opt = INT_MIN;
        helper(root, opt);
        return opt;
    }

private:
    int helper(Node* root, int& opt) {

        if (!root) {
            return 0;
        }

        int first = 0, second = 0;
        for (auto child : root->children) {
            int ret = helper(child, opt);

            if (ret > first) {
                second = first;
                first = ret;
            } else if (ret > second) {
                second = ret;
            }
        }

        opt = max(opt, first + second);
        return first + 1;
    }
};