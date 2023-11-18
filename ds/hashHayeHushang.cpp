#include <bits/stdc++.h>

using namespace std;
#define foreach(iter, ele) for (auto ele : iter)
#define aloc(__n) reserve(__n)
#define pb(ele) push_back(ele)

typedef long long int ll;

int pow(ll a, int b, int mod) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return (int)ans;
}

int main() {
  int N, X, M;
  cin >> N >> X >> M;
  int mod = (1 << M) - 1;

  vector<int> A[N / 2 + 1];
  A[0].pb(0);
  for (int i = 1; i <= N / 2; i++) {
    A[i].aloc(A[i - 1].size() * 26);
    foreach (A[i - 1], ele)
      for (int c = 1; c <= 26; c++)
        A[i].pb(((ele * 33) ^ c) & mod);
  }

  int n = N - N / 2;
  vector<int> B[n + 1];
  int inv = pow(33L, (1 << (M - 1)) - 1, 1 << M);
  B[0].pb(X);
  for (int i = 1; i <= n; i++) {
    B[i].aloc(B[i - 1].size() * 26);
    foreach (B[i - 1], ele)
      for (int c = 1; c <= 26; c++)
        B[i].pb(((ele ^ c) * inv) & mod);
  }

  vector<int> R(1 << M, 0);
  foreach (A[N / 2], ele)
    R[ele]++;

  ll ans = 0;
  foreach (B[n], ele)
    ans += R[ele];
  cout << ans << '\n';
}
