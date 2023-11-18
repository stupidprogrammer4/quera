#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 1e6 + 10;
ll a[maxn];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    ll sum = 0;
    for (int i = 0; i < n; i++)
      sum = sum + a[i];

    vector<ll> divisors, result;
    for (ll i = 1; i <= n; i++) {
      if (sum % i == 0) {
        divisors.push_back(i);
      }
    }
    ll psum;
    ll i, should, flag;
    for (ll d : divisors) {
      psum = flag = 0;
      should = sum / d;
      for (i = 0; i < n; i++) {
        if (psum == should) {
          i--;
          psum = 0;
          continue;
        }
        if (psum < should) {
          psum = psum + a[i];
          continue;
        }
        if (psum > should) {
          flag = 1;
          break;
        }
      }
      if (psum == should && !flag) {
        result.push_back(d);
      }
    }

    cout << result.size() << '\n';
    for (int r : result)
      cout << r << ' ';
    cout << '\n';
  }
}
