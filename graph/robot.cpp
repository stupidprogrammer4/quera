#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 250010;
#define pii pair<ll, ll>
#define min_heap priority_queue<pii, vector<pii>, greater<pii>>
#define F first
#define S second


vector<pii> adj[maxn];
ll a[5][510][510];
ll dist[maxn], t[maxn];
ll oo = 1e18;
ll n, m;

void dijkstra(ll src) {
    for (int i=1; i<=n*m; i++)
        dist[i] = oo;
    dist[src] = 0;
    min_heap pq;
    pq.push({0, src});
    while (pq.size()) {
        pii v = pq.top();
        pq.pop();
        for (auto u : adj[v.S]) {
            if (dist[u.F] > v.F + u.S) {
                dist[u.F] = v.F + u.S;
                pq.push({dist[u.F], u.F});
            }
        }
    }
}

int main() {
    
    cin>>n>>m;
    for (int k=0; k<4; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++)
                cin>>a[k][i][j];
        }
    }
    int v = 1;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ll y = 1e9;
            for (int k=0; k<4; k++) {
                y = min(y, a[k][i][j]);
            }
            for (int k=0; k<4; k++) {
                a[k][i][j] -= y;
            }
            t[v] = y;
            v++;
        }
    }

    v = 1; 
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int w = a[0][i][j];
            if (j == m) {
                v++;
                continue;
            }
            adj[v].push_back({v+1, w});
            v++;
        }
    }


    v = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int w = a[1][i][j];
            if (i == n) {
                v++;
                continue;
            }
            adj[v].push_back({v+m, w});
            v++;
        }
    }

    v = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int w = a[2][i][j];
            if (j == 1) {
                v++;
                continue;
            }
            adj[v].push_back({v-1, w});
            v++;
        }
    }

    v = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int w = a[3][i][j];
            if (i == 1) {
                v++;
                continue;
            }
            adj[v].push_back({v-m, w});
            v++;
        }
    }

    dijkstra(1);
    ll ans = dist[n*m];

    for (int i=1; i<=n*m; i++)
        ans += t[i];
    cout<<ans<<'\n';
}