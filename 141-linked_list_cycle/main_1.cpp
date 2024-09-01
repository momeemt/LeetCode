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
        if (std::find(visited_nodes.begin(), visited_nodes.end(), head) != visited_nodes.end()) {
            return true;
        }
        visited_nodes.push_back(head);
        return hasCycle(head->next);
    }
    std::vector<ListNode*> visited_nodes;
};
