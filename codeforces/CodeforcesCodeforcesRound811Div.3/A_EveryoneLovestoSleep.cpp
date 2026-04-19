// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1714/A
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
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

#define rep(x) for (int i = 0; i < x; i++)

void _print(long long t) { coutc << t; }
void _print(int t) { coutc << t; }
void _print(string t) { coutc << t; }
void _print(char t) { coutc << t; }
void _print(double t) { coutc << t; }
int convert_to_mins(pair<int, int> time) {
  int mins = time.first * 60;
  mins += time.second;
  return mins;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    pair<int, int> bed_time;
    int n;
    cin >> n >> bed_time.first >> bed_time.second;
    vector<pair<int, int>> v;
    int a, b;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }

    int min_time = INT_MAX;
    for (int i = 0; i < n; i++) {
      int a = convert_to_mins(v[i]);
      int b = convert_to_mins(bed_time);
      int time_to_wake = a >= b ? a - b : ((1440 - b) + a);
      debug(time_to_wake);
      if (time_to_wake >= 0 && time_to_wake < min_time)
        min_time = time_to_wake;
    }
    cout << min_time / 60 << " " << min_time % 60;
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(nullptr);
  solve();
  return 0;
}
