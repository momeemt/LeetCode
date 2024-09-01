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
        while (head) {
            vals.insert(head->val);
            head = head->next;
        }
        return buildUniqueListNode(vals);
    }
    
private:
    ListNode* buildUniqueListNode(std::set<int> vals) {
        if (vals.empty()) {
            return nullptr;
        }
        ListNode* unique_listnode = new ListNode(*vals.begin());
        ListNode* result = unique_listnode;
        for (int i = 1; i < vals.size(); i++) {
            auto it = vals.begin();
            advance(it, i);
            unique_listnode->next = new ListNode(*it);
            unique_listnode = unique_listnode->next;
        }
        return result;
    }
};
