
// Definition for singly-linked list.
#include <cstddef>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int has_k_nodes(ListNode *head, int k) {
    int count = 1;
    // cout<<head->val<<endl;
    while (count <= k) {
      if (head == NULL)
        return 0;
      head = head->next;
      count++;
    }
    // cout<<head->val<<endl;
    return 1;
  }
  ListNode *get_last_node(ListNode *head) {
    while (head->next) {
      head = head->next;
    }
    return head;
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 0 || k == 1) {
      return head;
    }
    // insert a dummy node at head
    head = new ListNode(-1, head);
    ListNode *prev_group = head, *current = head->next, *prev = NULL,
             *next = NULL;
    int count = k;
    while (has_k_nodes(current, k)) {
      count = k;
      // reverse nodes
      prev = NULL;
      while (count--) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      }
      ListNode *temp = get_last_node(prev);
      temp->next = current;
      prev_group->next = prev;
      prev_group = temp;
    }
    return head->next;
  }
};
