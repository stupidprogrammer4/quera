#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3 + 10;
long long dp[maxn][maxn][2], a[maxn];

int main() {
  int n, B;
  cin >> n >> B;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  dp[1][1][1] = (long long)a[0];
  dp[1][0][1] = dp[1][1][0] = INT64_MAX;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= B; j++) {
      if (j == 0) {
        dp[i][j][1] = INT64_MAX;
        continue;
      } else if (i == j) {
        dp[i][j][0] = INT64_MAX;
        dp[i][j][1] = dp[i - 1][j - 1][1];
        continue;
      } else if (j > i) {
        dp[i][j][1] = INT64_MAX;
        dp[i][j][0] = INT64_MAX;
        continue;
      }
      dp[i][j][0] = min(dp[i - 1][j][1] + (long long)a[i - 1], dp[i - 1][j][0]);
      dp[i][j][1] =
          min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][0] + (long long)a[i - 1]);
    }
  }
  long long ans = INT64_MAX;
  for (int i = n - B; i <= B; i++) {
    long long d = min(dp[n][i][0], dp[n][i][1]);
    ans = min(d, ans);
  }
  cout << ans << '\n';
  return 0;
}
