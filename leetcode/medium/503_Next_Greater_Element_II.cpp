#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> nge(nums.size());
    stack<int> s;
    // fill the stack initally
    for (int i = nums.size() - 1; i >= 0; i--) {
      while (!s.empty() && s.top() <= nums[i]) {
        s.pop();
      }
      s.push(nums[i]);
    }
    for (int i = nums.size() - 1; i >= 0; i--) {
      while (!s.empty() && s.top() <= nums[i]) {
        s.pop();
      }
      nge[i] = s.empty() ? -1 : s.top();
      s.push(nums[i]);
    }
    return nge;
  }
};
