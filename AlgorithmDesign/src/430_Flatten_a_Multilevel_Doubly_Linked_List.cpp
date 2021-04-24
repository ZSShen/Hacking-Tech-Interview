/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        /**
         * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
         *
         * TC: O(N)
         * SC: O(N)
         */

        if (!head) {
            return nullptr;
        }

        Node dummy;
        dummy.next = head;

        stack<Node*> stk;
        stk.emplace(head);
        Node *pred = &dummy;

        while (!stk.empty()) {

            auto curr = stk.top();
            stk.pop();

            while (curr) {
                pred->next = curr;
                curr->prev = pred;
                pred = curr;

                if (curr->child) {
                    stk.emplace(curr->next);
                    stk.emplace(curr->child);
                    curr->child = nullptr;
                    break;
                }
                curr = curr->next;
            }
        }

        auto new_head = dummy.next;
        new_head->prev = nullptr;
        return new_head;
    }
};