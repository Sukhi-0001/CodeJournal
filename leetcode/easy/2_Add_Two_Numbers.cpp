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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1, NULL), *tail = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
      int d1 = 0, d2 = 0, sum = 0;
      if (l1) {
        d1 = l1->val;
        l1 = l1->next;
      }
      if (l2) {
        d2 = l2->val;
        l2 = l2->next;
      }
      sum = carry + d1 + d2;
      carry = sum / 10;
      tail->next = new ListNode(sum % 10, NULL);
      tail = tail->next;
    }
    return dummy->next;
  }
};
