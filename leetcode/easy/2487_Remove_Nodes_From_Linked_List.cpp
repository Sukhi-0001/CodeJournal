#include <bits/stdc++.h>
#include <stack>
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
  ListNode *removeNodes(ListNode *head) {
    ListNode *current = head;
    std::stack<ListNode *> s;
    while (current) {
      s.push(current);
      current = current->next;
    }
    head = NULL;
    int max = 0;
    while (!s.empty()) {
      current = s.top();
      s.pop();
      if (current->val >= max) {
        max = current->val;
        current->next = head;
        head = current;
      }
    }
    return head;
  }
};
