
//  Definition for singly-linked list.
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
  ListNode *get_last_node(ListNode *head) {
    while (head->next) {
      head = head->next;
    }
    return head;
  }
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right)
      return head;
    ListNode *current = head, *prev = NULL, *before_index = NULL;
    int index = 1;
    while (index < left) {
      before_index = current;
      current = current->next;
      index++;
    }
    // start reversing from here
    while (index <= right) {

      ListNode *next = current->next;
      current->next = prev;
      prev = current;

      current = next;

      index++;
    }
    // find the end node
    ListNode *temp = get_last_node(prev);
    temp->next = current;

    //  then we need to change head ptr
    if (left == 1)
      head = prev;
    else {
      before_index->next = prev;
    }

    return head;
  }
};
