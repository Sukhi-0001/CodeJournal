
#include <bits/stdc++.h>
#include <cstdlib>
#include <stack>
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
  bool isPalindrome(ListNode *head) {
    bool result = true;
    ListNode *current = head;
    stack<ListNode *> s;
    while (current) {
      s.push(current);
      current = current->next;
    }
    // compare
    current = head;
    while (current) {
      if (s.top()->val != current->val) {
        result = false;
        break;
      }
      s.pop();
      current = current->next;
    }

    return result;
  }
};
