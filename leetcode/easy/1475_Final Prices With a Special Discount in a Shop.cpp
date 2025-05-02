#include <bits/stdc++.h>
#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> finalPrices(std::vector<int> &prices) {
    std::vector<int> v;
    std::stack<int> s;
    for (int i = 0; i < prices.size(); i++) {
      if (!s.empty() && prices[s.top()] >= prices[i]) {
        while (!s.empty() && s.top() <= prices[s.top()]) {
          prices[s.top()] -= prices[i];
          s.pop();
        }
      }
      s.push(i);
    }

    return prices;
  }
};
