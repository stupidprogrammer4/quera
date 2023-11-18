#include <bits/stdc++.h>

using namespace std;
#define key first
#define val second
const int maxn = 2e5 + 10;

int main() {
  int n, t;
  cin >> n;
  map<int, int> cntA, cntB;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (cntA.find(t) == cntA.end())
      cntA.insert({t, 1});
    else
      cntA[t] += 1;
  }
  int a[cntA.size()], i = 0;
  for (auto p : cntA)
    a[i++] = p.val;
  std::sort(a, a + cntA.size());
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (cntB.find(t) == cntB.end())
      cntB.insert({t, 1});
    else
      cntB[t] += 1;
  }

  multiset<int> s;
  vector<int> v;
  for (auto p : cntB)
    s.insert(p.val);
  int ans = 0;
  for (i = 0; i < cntA.size(); i++) {
    v.clear();
    for (int j = 0; j < a[i]; j++) {
      if (s.empty())
        break;
      ans++;
      auto it = s.end();
      it--;
      s.erase(it);
      v.push_back(*it - 1);
    }
    for (auto j : v)
      if (j)
        s.insert(j);
  }
  cout << ans << '\n';
  return 0;
}
