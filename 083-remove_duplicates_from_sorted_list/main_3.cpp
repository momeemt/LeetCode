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
        std::set<int> vals;
        while(head) {
            vals.insert(head->val);
            head = head->next;
        }
        return buildUniqueListNode(vals);
    }

private:
    ListNode* buildUniqueListNode(std::set<int> vals) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        for (int val: vals) {
            current->next = new ListNode(val);
            current = current->next;
        }
        return dummy->next;
    }
};
