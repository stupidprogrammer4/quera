#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    s.insert(tmp);
  }
  int ans = 0;
  for (auto it = s.begin(); it != s.end(); it++) {
    auto node = --s.upper_bound(*it + d);
    if (node != s.end() && node != it) {
      it = node;
      ans++;
      continue;
    }
    ans++;
  }
  cout << ans << '\n';
  return 0;
}
