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
  ListNode *deleteDuplicates(ListNode *head) {
    set<int> vals = {};
    set<int> duplicates_vals = {};
    while (head != nullptr) {
      auto [_, added] = vals.insert(head->val);
      if (!added) {
        duplicates_vals.insert(head->val);
      }
      head = head->next;
    }
    ListNode *dummy = new ListNode();
    ListNode *it = dummy;
    for (auto val : vals) {
      if (duplicates_vals.find(val) == duplicates_vals.end()) {
        it->next = new ListNode(val);
        it = it->next;
      }
    }
    ListNode *result = dummy->next;
    delete dummy;
    return result;
  }
};
