#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll oo = 1e16;

struct c_map {
  map<ll, ll> mp;

  void insert(ll s, ll cost) {
    auto it = mp.lower_bound(s);
    if (it != mp.end() && it->second <= cost)
      return;
    vector<int> rm;
    if (it != mp.begin()) {
      it--;
      while (true) {
        if (it->second < cost)
          break;
        rm.push_back(it->first);
        if (it == mp.begin())
          break;
        it--;
      }
    }
    for (ll i : rm)
      mp.erase(i);

    mp[s] = cost;
  }

  ll get(ll x) {
    auto it = mp.lower_bound(x);
    if (it == mp.end())
      return oo;
    return it->second;
  }
} l, r;

int main() {
  ll m, n;
  cin >> m >> n;
  l.insert(1, 0);
  r.insert(-n, 0);
  ll ans = oo;
  for (ll i = 0; i < m; i++) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll lcost = l.get(a), rcost = r.get(-b);
    ans = min(ans, lcost + rcost + d);
    l.insert(c, lcost + d);
    r.insert(-c, rcost + d);
  }
  ans = ans == oo ? -1 : ans;
  cout << ans << '\n';
}
