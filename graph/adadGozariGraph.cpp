#include <bits/stdc++.h>

using namespace std;

#define int long long int

const int maxn=1e5+10, mod=1e9+7;
vector<int> adj[maxn];
int deg[maxn], h[maxn], can=1;
bool mark[maxn];

void dfs(int v, int par=0) {
    mark[v] = true;
    h[v] = h[par] + 1;
    for (int u : adj[v]) {
        if (!mark[u]) dfs(u, v);
        else if (u != par) {
            can = 0;
        }
    }      
} 

int32_t main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k, u, v;
    cin>>n>>m>>k;

    for (int i=0; i<m; i++) {
        cin>>u>>v;
        deg[v]++, deg[u]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src=0;
    for (int i=1; i<=n; i++) {
        if (deg[i] == 1) src = i;
        else if (deg[i] > 2) {
            can = 0;
            break;
        }
    }
    dfs(max(src, 1LL));
    if (!can || k < n) {
        cout<<"0\n";
        return 0;
    }
    int l=0;
    for (int i=1; i<=n; i++) l=max(l, h[i]);
    if (l == 1) {
        cout<<k<<'\n';
    }
    else if (k < l) {
        cout<<"0\n";
    }
    else {
        int ans = ((k+1-l)%mod+mod)%mod;
        ans = (ans*2LL)%mod;
        cout<<ans<<'\n';
    }
}
