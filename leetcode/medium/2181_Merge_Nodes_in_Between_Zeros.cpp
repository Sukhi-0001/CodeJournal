
//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {
    if (!head)
      return head;
    ListNode *current = head, *travel = head->next;
    int sum = 0;
    while (current->next) {
      if (travel->val == 0) {
        current->next = new ListNode(sum, travel);
        sum = 0;
        current = travel;
        travel = current->next;
      } else {
        sum += travel->val;
        travel = travel->next;
      }
    }
    current = head->next;
    while (current && current->next) {
      current->next = current->next->next;
      current = current->next;
    }
    return head->next;
  }
};
