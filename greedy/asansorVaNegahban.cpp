#include <bits/stdc++.h>

using namespace std;

#define pii pair<ll, ll>

typedef long long ll;
const int maxn = 3e5 + 10;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n, m;
  cin >> n >> m;
  vector<pii> v;

  for (int i = 0; i < m; i++) {
    pii x;
    cin >> x.first >> x.second;
    if (x.second < x.first)
      v.push_back(x);
  }

  sort(v.begin(), v.end(),
       [](const pii &p1, const pii &p2) { return p1.second < p2.second; });

  stack<pii> st;
  for (auto e : v) {
    if (st.empty()) {
      st.push(e);
      continue;
    }
    pii p = st.top();

    if (p.first > e.second) {
      st.pop();
      st.push({max(p.first, e.first), p.second});
    } else {
      st.push({e.first, e.second});
    }
  }

  ll ans = 0;

  while (st.size()) {
    pii p = st.top();

    ans += ((p.first - p.second) * 2);
    st.pop();
  }

  ans += (n - 1);
  cout << ans << '\n';
}
