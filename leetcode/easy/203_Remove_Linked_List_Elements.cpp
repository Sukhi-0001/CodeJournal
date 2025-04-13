
#include <bits/stdc++.h>
#include <cstddef>
#include <cstdlib>
using namespace std;

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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *current = head;
    if (!head)
      return head;
    while (head && head->val == val) {
      if (head->next) {
        head = head->next;
      } else {
        head = NULL;
      }
    }
    current = head;
    while (current && current->next) {
      if (current->next->val == val) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }

    return head;
  }
};
