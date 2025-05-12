#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> s;
    for (int i = 0; i < asteroids.size(); i++) {
      if (asteroids[i] > 0) {
        s.push(asteroids[i]);
      } else {
        while (!s.empty() && s.top() > 0 && abs(s.top()) < abs(asteroids[i])) {
          s.pop();
        }
        if (!s.empty() && s.top() > 0 && abs(s.top()) == abs(asteroids[i])) {
          s.pop();
          continue;
        }
        if (s.empty() || s.top() < 0) {
          s.push(asteroids[i]);
        }
      }
    }

    vector<int> v(s.size());

    for (int i = v.size() - 1; i >= 0; i--) {
      v[i] = s.top();
      s.pop();
    }

    return v;
  }
};
