#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
class Solution {
public:
  int sumSubarrayMins(vector<int> &arr) {
    stack<int> s;
    vector<int> nse(arr.size()), pse(arr.size());
    long long sum = 0;
    // for nse start from back
    for (int i = arr.size() - 1; i >= 0; i--) {
      while (!s.empty() && arr[i] < arr[s.top()]) {
        s.pop();
      }
      nse[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }
    while (!s.empty()) {
      s.pop();
    }
    for (int i = 0; i < arr.size(); i++) {
      while (!s.empty() && arr[i] <= arr[s.top()]) {
        s.pop();
      }
      pse[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }
    // now nse and pse contains index
    for (int i = 0; i < arr.size(); i++) {
      // cout<<pse[i]<<" ";
      long long left_count = (pse[i] == -1) ? (i + 1) : (i - pse[i]);
      long long right_count = (nse[i] == -1) ? (arr.size() - i) : (nse[i] - i);
      long long product = left_count * right_count * arr[i];
      // cout << "for index " << i << endl;
      // cout << left_count << " " << right_count << endl;
      sum = (sum + product) % MOD;
    }
    return sum;
  }
};
