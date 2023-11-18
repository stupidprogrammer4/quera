#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn=1e6+10;
 
int a[maxn], parent[maxn], n, redNodeCountTree = 0;
ll dp1[maxn], dp2[maxn];
bool color[maxn], mark[maxn];
vector<int> childs[maxn], adj[maxn];

void buildTree(int v, int p) {
    if (p)
        childs[p].push_back(v);
    mark[v] = 1;
    parent[v] = max(parent[v], p);
    for (auto u : adj[v])
        if (!mark[u]) buildTree(u, v);
}

int dfs(int v) {
    dp1[v] = 1LL*a[v];
    if (childs[v].empty()) {
        if (color[v]) {
            if (redNodeCountTree == 1)
                dp2[v] = a[v];
            return 1;
        }
        return 0;
    }
    int redNodeCount = color[v] ? 1 : 0;
    
    for (auto u : childs[v]) {
        int redNodeCountSubTree = dfs(u);
        if (redNodeCountSubTree || dp1[v] + dp1[u] > dp1[v]) { 
            dp1[v] += dp1[u];
            redNodeCount += redNodeCountSubTree;
        }

        if (redNodeCountSubTree == redNodeCountTree) 
            dp2[v] = dp2[u];
        
    }
    if (redNodeCount == redNodeCountTree)
        dp2[v] = max(dp1[v], dp2[v]);

    return redNodeCount;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int v, u;
    char c;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>c;
        if (c == 'R') {
            color[i] = 1;
            redNodeCountTree++;
        }
        dp1[i] = dp2[i] = -1e17;
    }
    for (int i=1; i<=n; i++) cin>>a[i];

    for (int i=0; i<n-1; i++) {
        cin>>v>>u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    buildTree(1, 0);

    int r = dfs(1);
    cout<<max(dp1[1], dp2[1])<<'\n';
    
}
