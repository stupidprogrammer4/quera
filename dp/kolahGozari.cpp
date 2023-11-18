#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int dp[maxn][2];
vector<int> tree[maxn];

void dfs(int v) {
  if (!tree[v].size())
    return;

  for (int child : tree[v])
    dfs(child);

  vector<int> p, s;
  for (int child : tree[v]) {
    s.push_back(max(dp[child][0], dp[child][1]));
    p.push_back(max(dp[child][0], dp[child][1]));
  }

  for (int i = 1; i < p.size(); i++)
    p[i] += p[i - 1];
  for (int i = p.size() - 2; i >= 0; i--)
    s[i] += s[i + 1];

  dp[v][0] = s[0];
  int i = 0;
  for (int child : tree[v]) {
    int left = i == 0 ? 0 : p[i - 1], right = i == s.size() - 1 ? 0 : s[i + 1];
    dp[v][1] = max(dp[v][1], dp[child][0] + left + right + 1);
    i++;
  }
}

int main() {
  int n, c, p;
  cin >> n >> c;
  for (int i = 2; i <= n; i++) {
    cin >> p;
    tree[p].push_back(i);
  }
  int ans = 0;
  if (c == 1) {
    ans = n;
  } else if (c == 2) {
    dfs(1);
    ans = max(dp[1][1], dp[1][0]);
  }
  cout << ans << '\n';
}