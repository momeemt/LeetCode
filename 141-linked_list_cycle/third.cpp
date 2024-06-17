/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        auto [_, added] = visited.insert(head);
        if (!added) {
            return true;
        }
        return hasCycle(head->next);
    }
    std::set<ListNode*> visited;
};
