#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 5e2 + 10, maxk = 5e5 + 10, oo = 2e9;

vector<int> adj[maxn];
ll dist[maxn][maxn];
int s[maxk], d[maxk];
int n, m;

void bfs(int src) {
  queue<int> q;
  for (int i = 1; i <= n; i++)
    dist[src][i] = oo;

  dist[src][src] = 0;
  q.push(src);

  while (q.size()) {
    int v = q.front();
    q.pop();

    for (auto u : adj[v]) {
      if (dist[src][u] > dist[src][v] + 1) {
        dist[src][u] = dist[src][v] + 1;
        q.push(u);
      }
    }
  }
}

int main() {
  int u, v, k;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> v >> u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  cin >> k;
  for (int i = 0; i < k; i++)
    cin >> s[i];

  for (int i = 0; i < k; i++)
    cin >> d[i];

  for (int i = 1; i <= n; i++)
    bfs(i);

  ll ans = 0;
  for (int i = 0; i < k; i++) {
    if (dist[s[i]][d[i]] == oo) {
      ans = -1;
      break;
    }
    ans += dist[s[i]][d[i]];
  }

  cout << ans << '\n';
}
