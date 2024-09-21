#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define pii pair<int, int>
#define F first
#define S second

const int maxn=1e5+10, oo=1e18;
vector<int> adj[maxn];
int dp0[maxn], dp1[maxn], f[maxn], s[maxn];

void dfs(int v, int par=0) {
    /*
        h0 : set bomb into v
        h1 : set bomb to adj[v] - fv + 1 childs of v
    */
    int h0=s[v], h1=0, h2=0;
    int n = adj[v].size();
    vector<pii> ls;

    for (int u : adj[v]) {
        if (u == par) continue;

        dfs(u, v);
        ls.push_back({dp0[u], dp1[u]});
        h0 += dp1[u];
    }

    sort(ls.begin(), ls.end(), 
    [](const pii &p1, const pii &p2) { 
        return p1.F-p1.S < p2.F-p2.S;
    });

    int m = ls.size(), cnt0=0, cnt1=0;

    for (int i=0; i<m; i++) {
        if (i < n-f[v])
            h2 += ls[i].F, cnt1++;
        else
            h2 += ls[i].S;
        if (i < n-f[v]+1)
            h1 += ls[i].F, cnt0++;
        else
            h1 += ls[i].S;
    }
    if (cnt1 < n-f[v])
        h2 = oo;
    if (cnt0-1 < n-f[v])
        h1 = oo;
    dp0[v] = min(h0, h1);
    dp1[v] = min(h0, h2);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n, u, v;
    cin>>t;

    while (t--) {
        cin>>n;

        for (int i=1; i<=n; i++) adj[i].clear();

        memset(dp0, 0, sizeof dp0);
        memset(dp1, 0, sizeof dp1);
        for (int i=0; i<n-1; i++) {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i=1; i<=n; i++) cin>>f[i];
        for (int i=1; i<=n; i++) cin>>s[i];

        dfs(1);

        cout<<dp0[1]<<'\n';
    }
}