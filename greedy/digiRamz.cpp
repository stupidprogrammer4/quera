#include <bits/stdc++.h>

using namespace std;
#define pii pair<ll, ll>

typedef long long int ll;

ll n, m, st = 1, en = 1e9;

bool compare(pii p1, pii p2) {
  return p1.second / p1.first < p2.second / p2.first;
}

int main() {

  cin >> n >> m;
  vector<pii> a(n), ps(n + 1);

  for (int i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second;

  sort(a.begin(), a.end(), compare);

  for (int i = 1; i <= n; i++) {
    ps[i].first = ps[i - 1].first + a[i - 1].first;
    ps[i].second = ps[i - 1].second + a[i - 1].second;
  }

  int ans = INT32_MAX;
  for (int i = 1; i <= n; i++) {
    int day = ceil(((double)ps[i].second + (double)m) / (double)ps[i].first);
    ans = min(ans, day);
  }

  cout << ans << '\n';
}
