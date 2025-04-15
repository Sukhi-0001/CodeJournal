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
  ListNode *rotateRight(ListNode *head, int k) {
    int length = 0;
    ListNode *current = head;
    while (current) {
      length++;
      current = current->next;
    }
    if(k==0 || length==0)
        return head;
    int rotate = k % length;
    
    current = head;
    rotate=length - rotate;
    while (--rotate) {
      current = current->next;
    }
    
    ListNode *tail = current;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = head;
    head=current->next;
    current->next = NULL;
    return head;
  }
};
