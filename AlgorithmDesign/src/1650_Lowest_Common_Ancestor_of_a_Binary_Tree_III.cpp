/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {

        /**
         *  TC: O(n)
         *  SC: O(n)
         */

        unordered_set<Node*> set;
        while (p) {
            set.emplace(p);
            p = p->parent;
        }

        while (q) {
            if (set.count(q) == 1) {
                return q;
            }
            q = q->parent;
        }

        return nullptr;
    }
};