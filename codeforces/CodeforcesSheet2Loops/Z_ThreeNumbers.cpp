// time-limit: 3000
// problem-url: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/Z
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define coutc cout << "\033[31m" // red color code
#define endlc "\033[0m" << endl; // this resets the coloring
// Debug Overloads
#ifdef DEBUG
#define debug(x)                                                               \
  _print(x);                                                                   \
  coutc << endlc;
#else
#define debug(x)
#endif
void _print(long long t) { coutc << t; }
void _print(int t) { coutc << t; }
void _print(string t) { coutc << t; }
void _print(char t) { coutc << t; }
void _print(double t) { coutc << t; }

void solve() {
  int k, s;
  cin >> k >> s;
  int count = 0;
  for (int x = 0; x <= k; x++) {
    for (int y = 0; y <= k; y++) {
      int z = s - x - y;
      if (z >= 0 && z <= k)
        count++;
    }
  }

  cout << count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(nullptr);
  solve();
  return 0;
}
