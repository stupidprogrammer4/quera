#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// https://quera.org/problemset/316164
// Floyd on fuel distances, then on the cost of buying each leg's fuel at its start.
// Time: O(n^3), memory: O(n^2).

const int maxn = 5e2+10;
const ll oo = 1e18;

ll a[maxn], dist[maxn][maxn];
int n, m;

void floyd() {
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            if (dist[i][k] == oo) continue;
            for (int j=1; j<=n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int u, v, w;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            dist[i][j] = (i == j ? 0 : oo);

    for (int i=0; i<m; i++) {
        cin>>u>>v>>w;
        dist[u][v] = dist[v][u] = w;
    }

    floyd();
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            dist[i][j] *= a[i];
    floyd();

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++)
            cout<<dist[i][j]<<' ';
        cout<<'\n';
    }
}
