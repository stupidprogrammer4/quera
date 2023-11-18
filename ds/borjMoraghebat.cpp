#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  auto compare = [](const pii &p1, const pii &p2) {
    return p1.first < p2.first;
  };
  set<pii, decltype(compare)> s(compare);
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    int key = a[i], j = i + 1;
    while (j < n && a[j] < a[i]) {
      s.insert({a[j], j});
      j++;
    }
    if (j == n) {
      auto b = --s.end();
      ans = max(ans, (*b).second - i + 1);
    } else
      ans = max(ans, j - i + 1);
    s.clear();
  }
  cout << ans << '\n';
  return 0;
}
