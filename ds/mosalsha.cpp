#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
int solve(vii triangle, int n) {
  int dp[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == 0 and j == 0) {
        dp[i][j] = triangle[i][j];
        continue;
      }
      int left_parent = INT32_MIN;
      int right_parent = INT32_MIN;
      if (j > 0) {
        right_parent = dp[i - 1][j - 1];
      }
      if (j < i) {
        left_parent = dp[i - 1][j];
      }
      dp[i][j] = max(left_parent, right_parent) + triangle[i][j];
    }
  }
  int ans = INT32_MIN;
  for (int i = 0; i < n; i++)
    ans = max(ans, dp[n - 1][i]);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n;
  cin >> t;
  int result[t];
  for (int i = 0; i < t; i++) {
    cin >> n;
    vii triangle(n);
    for (int j = 0; j < n; j++) {
      for (int k = 0; k <= j; k++) {
        int tmp;
        cin >> tmp;
        triangle[j].push_back(tmp);
      }
    }
    result[i] = solve(triangle, n);
  }
  for (int i = 0; i < t; i++)
    cout << result[i] << '\n';
}
