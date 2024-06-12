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
    std::map<int, int> num_node_val;
    ListNode *current = head;
    while (current) {
      num_node_val[current->val]++;
      current = current->next;
    }
    return buildDistinctListNode(num_node_val);
  }

private:
  ListNode *buildDistinctListNode(std::map<int, int> num_node_val) {
    ListNode *deduplicated = new ListNode(0);
    ListNode *current = deduplicated;
    for (auto [val, num_val] : num_node_val) {
      if (num_val == 1) {
        current->next = new ListNode(val);
        current = current->next;
      }
    }
    return deduplicated->next;
  }
};
