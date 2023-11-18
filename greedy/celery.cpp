#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

const int maxn = 1e5 + 10, oo = 2e9;
queue<pii> q[maxn];

struct Person {
  int p, index, qnumber;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, l, t;
  cin >> n;
  auto cmp = [](const Person &p1, const Person &p2) {
    if (p1.p == p2.p && p1.qnumber != p2.qnumber) {
      return p1.qnumber < p2.qnumber;
    }
    if (p1.p == p2.p && p1.qnumber == p2.qnumber) {
      return p1.index < p2.index;
    }
    return p1.p < p2.p;
  };
  set<Person, decltype(cmp)> s(cmp);
  multiset<int> ms;

  for (int i = 0; i < n; i++) {
    cin >> l;
    for (int j = 0; j < l; j++) {
      cin >> t;
      q[i].push({t, j});
      s.insert({t, j, i});
      ms.insert(t);
    }
  }

  bool run = 0;
  int ans = 0;
  while (s.size()) {
    Person p = *s.begin();

    int i = 0;
    while (i <= p.index) {
      auto it = ms.upper_bound(ans);
      run = it != ms.begin();
      if (run)
        break;
      pii v = q[p.qnumber].front();
      q[p.qnumber].pop();
      s.erase({v.first, v.second, p.qnumber});
      ms.erase(ms.find(v.first));
      ans++;
      i = v.second + 1;
    }

    if (run)
      break;
  }

  cout << ans << '\n';
}
