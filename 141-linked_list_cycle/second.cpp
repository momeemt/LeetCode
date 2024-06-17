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
        if (std::find(visited.begin(), visited.end(), head) != visited.end()) {
            return true;
        }
        visited.push_back(head);
        return hasCycle(head->next);
    }
    std::vector<ListNode*> visited;
};

