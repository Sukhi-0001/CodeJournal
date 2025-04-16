#include <bits/stdc++.h>
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
  ListNode *partition(ListNode *head, int x) {
    ListNode *dummy = new ListNode(0, NULL), *tail = dummy;
    if (!head)
      return head;
    while (head && head->val >= x) {
      tail->next = head;
      tail = tail->next;
      head = head->next;
      tail->next = NULL;
    }
    ListNode *current = head;
    while (current && current->next) {
      if (current->next->val >= x) {
        tail->next = current->next;
        current->next = current->next->next;
        tail = tail->next;
        tail->next = NULL;
      } else {
        current = current->next;
      }
    }
    if (current)
      current->next = dummy->next;
    if (!head)
      return dummy->next;
    return head;
  }
};
