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
    std::map<int, int> val_to_num_node;
    ListNode *current = head;
    while (current) {
      val_to_num_node[current->val]++;
      current = current->next;
    }
    return buildDistinctListNode(val_to_num_node);
  }

private:
  ListNode *buildDistinctListNode(std::map<int, int> val_to_num_node) {
    ListNode *deduplicated = new ListNode(0);
    ListNode *current = deduplicated;
    for (auto [val, num_node] : val_to_num_node) {
      if (num_node == 1) {
        current->next = new ListNode(val);
        current = current->next;
      }
    }
    return deduplicated->next;
  }
};
