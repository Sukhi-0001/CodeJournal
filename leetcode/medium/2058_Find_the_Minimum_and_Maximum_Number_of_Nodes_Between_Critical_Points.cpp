#include <bits/stdc++.h>
#include <climits>
#include <utility>
#include <vector>
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
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    // check if legth is greater than 3
    int legth = 0;
    ListNode *current = head;
    while (current) {
      legth++;
      current = current->next;
      if (legth == 4)
        break;
    }
    if (legth <= 3) {
      vector<int> v = {-1, -1};
      return v;
    }
    // finding critical points
    vector<pair<int, ListNode *>> list;
    vector<int> v;
    ListNode *prev = head;
    current = head->next;
    int index = 2;
    while (current->next) {
      // check if current is crital point
      if ((prev->val > current->val && current->next->val > current->val) ||
          (prev->val < current->val && current->next->val < current->val)) {
        list.push_back(make_pair(index, current));
      }
      prev = current;
      current = current->next;
      index++;
    }
    for (int i = 0; i < list.size(); i++) {
      cout << list[i].first << " " << list[i].second->val << endl;
    }
    if (list.size() <= 1) {
      v.push_back(-1);
      v.push_back(-1);
      return v;
    }

    int max_dis = list[list.size() - 1].first - list[0].first;
    int min_dis = INT_MAX;
    for (int i = 0; i < list.size() - 1; i++) {
      if (min_dis > list[i + 1].first - list[i].first)
        min_dis = list[i + 1].first - list[i].first;
    }
    v.push_back(min_dis);
    v.push_back(max_dis);

    return v;
  }
};
