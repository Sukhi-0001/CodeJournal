#include <bits/stdc++.h>
#include <cstddef>
#include <cstdlib>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *result = NULL, *tempA = headA, *tempB = headB;
    // find length of both list.
    int countA = 0, countB = 0;
    while (tempA || tempB) {
      if (tempA) {
        countA++;
        tempA = tempA->next;
      }
      if (tempB) {
        countB++;
        tempB = tempB->next;
      }
    }
    // find the bigger list and move the pointer of it
    if (countB > countA) {
      tempA = headA;
      headA = headB;
      headB = tempA;
    }
    int diff = abs(countA - countB);
    while (diff) {
      diff--;
      headA = headA->next;
    }
    while (headA && headB) {
      if (headA == headB) {
        result = headA;
        break;
      }
      headA = headA->next;
      headB = headB->next;
    }

    return result;
  }
};
