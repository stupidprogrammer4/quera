#include <bits/stdc++.h>

using namespace std;

const int maxn = 100, mod = 1e9 + 7;

typedef unsigned long long int ull;

ull power(int x, ull y) {
  if (y == 0)
    return 1;

  ull temp = power(x, y / 2);

  if (y & 1)
    return (temp * temp * x) % mod;
  return (temp * temp) % mod;
}

int main() {
  int n, q;
  cin >> n >> q;
  int a[n], sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  while (q--) {
    unsigned long long int k;
    cin >> k;
    int result = (sum * 1LL * power(2, k - n - 1)) % mod;
    cout << result << '\n';
  }
  return 0;
}
