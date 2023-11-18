#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 2e6+10;
const ll oo = 4e18;

vector<int> adj[maxn];
ll dis[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int x, y;
    cin>>x>>y;

    int n = 6, layer = 1, cnt = 10;

    while (n < max(x, y)) {
        n += cnt;
        cnt *= 2;
        layer++;
    }

    int k = 2, c = 5, next = 0, min_next = 7, l = 1;
    for (int i=1; i<=n; i++) {
        if (i == 1) {
            for (int j=2; j<=6; j++) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
            continue;
        }
        if (i >= k + c) {
            k = i;
            c *= 2;
            min_next += c;
            l++;
        }
        if (l < layer) {
            next = min_next + (i - k)*2;
            for (int j=-1; j<=1; j++) {
                adj[next+j < min_next ? next+j+(c*2) : next+j].push_back(i);
                adj[i].push_back(next+j < min_next ? next+j+(c*2) : next+j);
            }
        }
        if (i == k + c - 1) {
            adj[i].push_back(k);
            adj[k].push_back(i);
            continue;
        }
        adj[i].push_back(i+1);
        adj[i+1].push_back(i);
    }


    for (int i=1; i<=n; i++)
        dis[i] = oo;

    dis[x] = 0;

    queue<int> q;
    q.push(x);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) {
            if (dis[u] > dis[v] + 1) {
                dis[u] = dis[v] + 1;
                q.push(u);
            }
        }
    }
    cout<<dis[y]<<'\n';
}