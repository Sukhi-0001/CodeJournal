#include <bits/stdc++.h>
#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *odd_dummy = new ListNode(-1, NULL),
             *even_dummy = new ListNode(-1, NULL);
    ListNode *odd = odd_dummy, *even = even_dummy;
    ListNode *current = head;
    int index = 1;
    while (current) {
      ListNode *next = current->next;
      if (index % 2 == 0) {
        even->next = current;
        even = even->next;
      } else {
        odd->next = current;
        odd = odd->next;
      }
      current->next = NULL;
      current = next;
      index++;
    }
    odd->next = even_dummy->next;
    return odd_dummy->next;
  }
};
