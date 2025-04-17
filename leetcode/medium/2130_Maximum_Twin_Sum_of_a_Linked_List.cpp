#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

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
  int pairSum(ListNode *head) {
    int result = 0;
    int n = 0;
    ListNode *current = head;
    while (current) {
      current = current->next;
      n++;
    }
    current = head;
    std::vector<int> v(n / 2, 0);

    int pos = 0;
    while (current) {
      if (pos < (n / 2)) {
        v[pos] += current->val;
      } else {
        v[n - pos - 1] += current->val;
      }
      current = current->next;
      pos++;
    }
    return *std::max_element(v.begin(), v.end());
  }
};
