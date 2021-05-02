class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        /**
         * https://leetcode.com/problems/validate-binary-tree-nodes/
         *
         * TC: O(N)
         * SC: O(N)
         */

        vector<vector<int>> graph(n);
        vector<int> indeg(n);
        int e = 0;

        for (int i = 0 ; i < n ; ++i) {
            if (leftChild[i] != -1) {
                graph[i].emplace_back(leftChild[i]);
                ++indeg[leftChild[i]];
                ++e;
            }
            if (rightChild[i] != -1) {
                graph[i].emplace_back(rightChild[i]);
                ++indeg[rightChild[i]];
                ++e;
            }
        }

        // # of edges = # of nodes - 1.
        if (e != n - 1) {
            return false;
        }

        // There should be only one root node.
        int root = -1;
        for (int i = 0 ; i < n ; ++i) {
            if (indeg[i] == 0) {
                if (root != -1) {
                    return false;
                }
                root = i;
            }
        }

        // There should be no cycle.
        vector<bool> visit(n);
        int count = 0;
        if (findCycle(root, graph, visit, count)) {
            return false;
        }

        // There should be only 1 connected component.
        return count == n;
    }

private:
    bool findCycle(
            int src,
            vector<vector<int>>& graph,
            vector<bool>& visit,
            int& count) {

        visit[src] = true;
        ++count;

        for (int dst : graph[src]) {
            if (visit[dst]) {
                return true;
            }
            bool res = findCycle(dst, graph, visit, count);
            if (res) {
                return true;
            }
        }
        return false;
    }
};