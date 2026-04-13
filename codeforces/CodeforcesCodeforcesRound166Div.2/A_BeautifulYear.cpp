// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/271/A
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int check(int a) {
  vector<int> v(10, 0);
  while (a) {
    int d = a % 10;
    a = a / 10;
    if (v[d] == 0)
      v[d] = 1;
    else
      return 0;
  }
  return 1;
}
void solve() {
  int yr;
  cin >> yr;
  while (1) {
    if (check(++yr) == 1)
      break;
  }
  cout << yr;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
