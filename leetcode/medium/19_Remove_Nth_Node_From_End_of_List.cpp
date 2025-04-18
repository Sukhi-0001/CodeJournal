#include <bits/stdc++.h>

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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int length = 0;
    ListNode *current = head;
    while (current) {
      current = current->next;
      length++;
    }

    if (n == length) {
      head = head->next;
      return head;
    }

    current = head;
    int from_front = length - n;
    while (--from_front) {
      current = current->next;
    }

    current->next = current->next->next;

    return head;
  }
};
