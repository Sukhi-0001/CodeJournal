#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> s;
    vector<int> nums2_greater(nums2.size());
    for (int i = nums2.size() - 1; i >= 0; i--) {
      while (!s.empty() && s.top() <= nums2[i]) {
        s.pop();
      }
      nums2_greater[i] = s.empty() ? -1 : s.top();
      s.push(nums2[i]);
    }
    unordered_map<int, int> map;
    for (int i = 0; i < nums2.size(); i++) {
      map.emplace(make_pair(nums2[i], i));
    }

    for (int i = 0; i < nums1.size(); i++) {
      nums1[i] = nums2_greater[map[nums1[i]]];
    }

    return nums1;
  }
};
