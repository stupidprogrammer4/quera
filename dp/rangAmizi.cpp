#include <bits/stdc++.h>

using namespace std;
#define MOD (ll)1000000007
#define N 1000010

typedef long long int ll;

bitset<N> is_sqfree;
vector<int> odd_factor_sqfree, even_factor_sqfree;
ll dp[N];
int fact_cnt[N];

ll pow(ll x, int y) {
  if (x == 0)
    return 0;

  ll res = 1;
  x = x % MOD;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % MOD;

    y = y >> 1;

    x = (x * x) % MOD;
  }

  return res;
}

inline void build() {
  for (int i = 2; i < N; i++)
    if (!fact_cnt[i])
      for (int j = 1; j * i < N; j++)
        fact_cnt[i * j]++;

  is_sqfree.set();
  for (int i = 2; i * i < N; i++)
    if (fact_cnt[i] == 1)
      for (int j = 1; j * i * i < N; j++)
        is_sqfree.reset(j * i * i);

  for (int i = 2; i < N; i++) {
    if (is_sqfree[i]) {
      if (fact_cnt[i] & 1)
        odd_factor_sqfree.push_back(i);
      else
        even_factor_sqfree.push_back(i);
    }
  }
}

int main() {
  int n, t, m = 0;
  cin >> n;
  build();

  for (int i = 0; i < n; i++) {
    cin >> t, dp[t]++;
    m = max(m, t);
  }

  for (int i = m; i > 0; i--) {
    for (int j : odd_factor_sqfree) {
      if (i * j > m)
        break;
      dp[i] += pow(dp[j * i], j);
    }

    for (int j : even_factor_sqfree) {
      if (i * j > m)
        break;
      dp[i] -= pow(dp[j * i], j);
    }

    dp[i] = ((dp[i] % MOD) + MOD) % MOD;
  }

  cout << dp[1] << '\n';
}
