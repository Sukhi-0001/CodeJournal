#include <bits/stdc++.h>
using namespace std;
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
  int numComponents(ListNode *head, vector<int> &nums) {
    set<int> s(nums.begin(), nums.end());
    int count = 0;
    ListNode *current = head;
    while (current) {
      if (s.find(current->val) != s.end() &&
          (!current->next || s.find(current->next->val) == s.end())) {
        count++;
      }
      current = current->next;
    }
    return count;
  }
};
