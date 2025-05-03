#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int count = 0;
    stack<int> s;
    vector<int> p_max(height.size()), n_max(height.size());
    int max = height[0];
    for (int i = 0; i < height.size(); i++) {
      if (max < height[i])
        max = height[i];
      p_max[i] = max;
    }
    while (!s.empty())
      s.pop();
    max = height[height.size() - 1];
    for (int i = height.size() - 1; i >= 0; i--) {
      if (max < height[i])
        max = height[i];
      n_max[i] = max;
    }

    for (int i = 0; i < height.size(); i++) {
      int temp = min(p_max[i], n_max[i]);
      if (temp > 0) {
        count += (temp - height[i]);
      }
    }
    return count;
  }
};
