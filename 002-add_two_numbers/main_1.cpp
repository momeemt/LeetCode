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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_current = l1;
        ListNode* l2_current = l2;
        ListNode dummy = ListNode(0);
        ListNode* result = &dummy;
        bool carry = false;
        while (l1_current || l2_current) {
            int l1_val = 0;
            if (l1_current) {
                l1_val = l1_current->val;
            }
            int l2_val = 0;
            if (l2_current) {
                l2_val = l2_current->val;
            }
            int val = l1_val + l2_val;
            if(carry) {
                val++;
            }
            carry = val >= 10;
            if (carry) {
                val -= 10;
            }
            result->next = new ListNode(val);
            result = result->next;
            if (l1_current) {
                l1_current = l1_current->next;
            }
            if (l2_current) {
                l2_current = l2_current->next;
            }
        }
        if (carry) {
            result->next = new ListNode(1);
            result = result->next;
        }
        result = dummy.next;
        delete l1_current;
        delete l2_current;
        return result;
    }
};
