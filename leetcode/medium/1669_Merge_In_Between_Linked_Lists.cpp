#include <bits/stdc++.h>

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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *a_ptr = list1, *b_ptr = list1, *current = list2;
    int count = 1;
    while (count <= b) {
      if (count < a)
        a_ptr = a_ptr->next;
      b_ptr = b_ptr->next;
      count++;
    }
    // get list2 last node
    while (current->next) {
      current = current->next;
    }
    a_ptr->next = list2;
    current->next = b_ptr->next;
    return list1;
  }
};
