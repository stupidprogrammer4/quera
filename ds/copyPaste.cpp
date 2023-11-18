#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int maxn = 2e5 + 10;
int a[maxn], b[maxn];

bool is_equal(int n) {
  for (int i = 0; i < n; i++)
    if (a[i] != b[i])
      return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  map<int, set<int>> m;

  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
    if (m.find(a[i]) == m.end()) {
      set<int> s;
      s.insert(i);
      m.insert({a[i], s});
    } else
      m[a[i]].insert(i);
  }
  for (int i = 0; i < 2 * n; i++)
    cin >> b[i];

  vector<pii> result;
  while (!is_equal(n)) {
    for (int i = 0; i < 2 * n; i++) {
      if (a[i] == b[i])
        continue;

      if (m[a[i]].size() == 1)
        continue;

      m[a[i]].erase(i);
      a[i] = b[i];
      result.push_back({i, *m[b[i]].begin()});
      m[b[i]].insert(i);
    }
  }

  cout << result.size() << '\n';
  for (auto p : result)
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}
