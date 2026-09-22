#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e2+10, oo = 1e9;

vector<int> child[maxn];
char c[maxn];
int n;
int dp[maxn][maxn], sz[maxn];

void dfs(int v, int K) {
    for (auto u : child[v])
        dfs(u, K);

    // dp[v][a] stores the smallest possible b; oo means impossible.
    for (int a=0; a<=K; a++)
        dp[v][a] = oo;

    // Start with v alone.
    dp[v][0] = 0;
    sz[v] = 1;

    for (auto u : child[v]) {
        int nxt[maxn];
        fill(nxt, nxt+K+1, oo);

        for (int a=0; a<sz[v] && a<=K; a++) {
            int b = dp[v][a];
            if (b == oo) continue;

            for (int x=0; x<sz[u] && x<=K; x++) {
                int d = dp[u][x];
                if (d == oo) continue;

                // v -> u: existing predecessors of v gain 1+x vertices.
                if (c[u] == 'D' || c[u] == '?') {
                    int nxt_a = a+1+x;
                    int nxt_b = b+1+x;
                    if (nxt_a <= K && nxt_b <= K)
                        nxt[nxt_a] = min(nxt[nxt_a], nxt_b);
                }

                // u -> v: predecessors of u gain v and its a reachable vertices.
                if (c[u] == 'U' || c[u] == '?') {
                    int nxt_b = max(b, d+1+a);
                    if (nxt_b <= K)
                        nxt[a] = min(nxt[a], nxt_b);
                }
            }
        }

        // Finish this merge before processing the next child.
        for (int a=0; a<=K; a++)
            dp[v][a] = nxt[a];
        sz[v] += sz[u];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, p;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i=1; i<=n; i++)
            child[i].clear();

        for (int i=2; i<=n; i++) {
            cin>>p>>c[i];
            child[p].push_back(i);
        }
    }
}
