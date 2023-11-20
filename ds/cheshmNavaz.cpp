#include <bits/stdc++.h>

using namespace std;

#define int long long int

const int mod = 1e9 + 7;

int power(int x, int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }

  return res % mod;
}

int solve(int n, int m) {
  if (n < m)
    swap(n, m);

  if (m == 1) {
    int res = power(3, n - 1);
    res = (res * 4) % mod;
    return res;
  }

  int p0 = power(2, m);
  p0 = (p0 * 6) % mod;

  int p1 = power(2, n);
  p1 = (p1 * 6) % mod;

  int res = ((p0 + p1 - 24) % mod + mod) % mod;
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cout << solve(n, m) << '\n';
  }
}
