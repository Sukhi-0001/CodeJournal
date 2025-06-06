#include <bits/stdc++.h>
#include <cstddef>
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
  ListNode *mergeList(ListNode *head1, ListNode *head2) {

    ListNode *dummy = new ListNode(-1, NULL), *tail = dummy;
    while (head1 && head2) {
      if (head1->val < head2->val) {
        tail->next = head1;
        tail = tail->next;
        head1 = head1->next;
        tail->next = NULL;
      } else {
        tail->next = head2;
        tail = tail->next;
        head2 = head2->next;
        tail->next = NULL;
      }
    }
    if (head1) {
      tail->next = head1;
    }
    if (head2) {
      tail->next = head2;
    }
    return dummy->next;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = NULL;
    for (int i = 0; i < lists.size(); i++) {
      head = mergeList(head, lists[i]);
    }
    return head;
  }
};
