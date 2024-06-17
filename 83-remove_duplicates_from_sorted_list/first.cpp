/**
* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* result = head;
        ListNode* current_node = result;
        while (head) {
            if (current_node->val != head->val) {
                current_node->next = head;
                current_node = current_node->next;
            }
            head = head->next;
        }
        current_node->next = nullptr;
        return result;
    }
};
