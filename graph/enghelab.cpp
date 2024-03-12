#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define F first 
#define S second 
#define int long long int

const int maxn=5e5+10, mod=1e9+7;
vector<pii> adj[maxn];
vector<int> tree[maxn];
pii edges[maxn];
int mark[maxn], dp[maxn], 
h[maxn], bridge[maxn], 
comp[maxn], cnt[maxn], deg[maxn], compid;


int power(int x, int y) {
    int res=1;
    while (y) {
        if (y & 1LL)  
            res = (res * x) % mod;
        y >>= 1LL;
        x = (x * x) % mod;
    }
    return res;
}

void dfs(int v, int par=0, int edge_id=-1) {
    mark[v] = true;
    dp[v] = h[v];
    for (auto &u : adj[v]) 
        if (!mark[u.F]) {
            h[u.F] = h[v] + 1;
            dfs(u.F, v, u.S);
            dp[v] = min(dp[u.F], dp[v]); 
        }
        else if (u.F != par)
            dp[v] = min(h[u.F], dp[v]);

    if (par != 0 and dp[v] > h[par]) 
        bridge[edge_id] = true;
}

void dfs1(int v) {
    mark[v] = true;
    comp[v] = compid, cnt[compid]++;
    for (auto &u : adj[v]) {
        if (bridge[u.S] || mark[u.F]) continue;
        dfs1(u.F);
    }
}

int32_t main() {
    int n, m, u, v;
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        cin>>u>>v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edges[i] = {v, u};
    }
    dfs(1);
    memset(mark, 0, sizeof mark);
    for (int i=1; i<=n; i++) {
        if (mark[i]) continue;
        dfs1(i);
        compid++;
    }
    for (int i=0; i<m; i++) 
        if (bridge[i]) {
            deg[comp[edges[i].F]]++;
            deg[comp[edges[i].S]]++;
        }
    int M=0, ans=1;
    for (int i=0; i<compid; i++) {
        if (deg[i] <= 1) {
            int tmp = ((power(2LL, cnt[i])-1)%mod+mod)%mod;
            ans = (ans * tmp) % mod;
        }
        else  
            M += cnt[i];
    }
    int tmp = power(2LL, M);
    ans = (ans * tmp) % mod;
    cout<<ans<<'\n';
}
