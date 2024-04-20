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
    ListNode *detectCycle(ListNode *head) {
        std::set<ListNode*> visited;
        ListNode *current = head;
        while(current != nullptr) {
            auto [_, added] = visited.insert(current);
            if (!added) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};
