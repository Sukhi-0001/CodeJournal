#include <bits/stdc++.h>
#include <set>
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
  ListNode *modifiedList(vector<int> &nums, ListNode *head) {
    set<int> s(nums.begin(), nums.end());
    ListNode *current = head, *prev = NULL;
    while (current) {
      if (s.find(current->val) != s.end()) {
        // check if it is head
        if (head == current) {
          head = head->next;
          current = current->next;
        } else {
          prev->next = current->next;
          current = current->next;
        }
      } else {
        prev = current;
        current = current->next;
      }
    }
    return head;
  }
};
