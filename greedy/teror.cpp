#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  map<int, int> intervals;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    if (intervals.find(l) != intervals.end())
      intervals[l] = max(intervals[l], r);
    else
      intervals.insert(make_pair(l, r));
  }
  set<int> s1, s2;
  for (int i = 1; i <= n; i++) {
    if (intervals.find(i) != intervals.end())
      s2.insert(intervals[i]);
    if (s1.empty()) {
      ans++;
      s1 = s2;
    }
    if (s1.find(i) != s1.end())
      s1.erase(i);
    if (s2.find(i) != s2.end())
      s2.erase(i);
  }
  cout << ans;
  return 0;
}
