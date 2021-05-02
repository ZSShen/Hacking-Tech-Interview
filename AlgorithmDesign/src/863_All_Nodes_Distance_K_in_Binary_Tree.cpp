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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

        /**
         * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
         *
         * TC: O(N)
         * SC: O(N)
         */

        unordered_map<TreeNode*, unordered_set<TreeNode*>> graph;
        buildGraph(root, graph);

        vector<int> ans;
        findNodes(target, nullptr, graph, K, ans);
        return ans;
    }

private:
    void buildGraph(
        TreeNode* root, unordered_map<TreeNode*, unordered_set<TreeNode*>>& graph) {

        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            if (node->left) {
                graph[node->left].emplace(node);
                graph[node].emplace(node->left);
                q.emplace(node->left);
            }
            if (node->right) {
                graph[node->right].emplace(node);
                graph[node].emplace(node->right);
                q.emplace(node->right);
            }
        }
    }

    void findNodes(
        TreeNode* curr, TreeNode* pred,
        unordered_map<TreeNode*, unordered_set<TreeNode*>>& graph,
        int k, vector<int>& ans) {

        if (k == 0) {
            ans.emplace_back(curr->val);
        }

        for (auto neighbor : graph[curr]) {
            if (neighbor != pred) {
                findNodes(neighbor, curr, graph, k - 1, ans);
            }
        }
    }
};