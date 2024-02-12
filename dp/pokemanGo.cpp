#include <bits/stdc++.h>

using namespace std;

#define INF 1'000'000'000
#define pii pair<int, int>
#define F first 
#define S second 

const int maxn=2e5+10;
vector<int> adj[maxn];
int dp1[maxn], dp2[maxn];
pii a[maxn];

void dfs1(int v, int par=0) {
    for (int u : adj[v]) {
        if (u == par) continue;
        dfs1(u, v);
        dp1[v] = max(dp1[v], dp1[u]+1);
    }
}

void dfs2(int v, int par=0) {
    int mx=-1, mx_disp=-1;
    for (int u : adj[v]) {
        if (u == par) continue;
        if (mx == -1 || dp1[u] > dp1[mx])
            mx_disp = mx, mx = u;
        else if (mx_disp == -1 || dp1[u] > dp1[mx_disp])
            mx_disp = u;
    }

    for (int u : adj[v]) {
        if (u == par) continue;
        dp2[u] = max(dp2[u], dp2[v]+1);
        if (u == mx) {
            if (mx_disp != -1)
                dp2[u] = max(dp2[u], dp1[mx_disp]+2);
        }
        else if (mx_disp != -1)
            dp2[u] = max(dp2[u], dp1[mx]+2);
        dfs2(u, v);
    }
}

int main() {
    int n, q, v, u, d;
    cin>>n>>q;
    for (int i=1; i<maxn; i++) dp1[i] = dp2[i] = -INF;
    for (int i=0; i<n-1; i++) {
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for (int i=0; i<q; i++) cin>>a[i].F>>a[i].S, dp2[a[i].F]=dp1[a[i].F]=-a[i].S;
    dfs1(1);
    dfs2(1);
    string ans;
    ans.reserve(n);
    for (int i=1; i<=n; i++) {
        if (max(dp1[i], dp2[i]) <= 0) {
            ans.push_back('1');
            dp1[i] = dp2[i] = 0;
        }
        else {
            ans.push_back('0');
            dp1[i] = dp2[i] = -INF;
        }
    }
    dfs1(1);
    dfs2(1);
    bool check=1;
    for (int i=0; i<q; i++) 
        if (max(dp1[a[i].F], dp2[a[i].F]) != a[i].S) {
            check = 0;
            break;
        }

    if (check) {
        cout<<ans<<'\n';
    }
    else 
        cout<<"-1\n";
}
