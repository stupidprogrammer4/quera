#include <bits/stdc++.h>
using namespace std;

#define pB(ele) push_back(ele)

const int maxn = 1e2 + 10, maxk = maxn * 10;
int g[maxn], h[maxn];
int dp[maxn][maxk];
vector<int> G, H;

int solve(int k) {
    for (int i = 0; i < G.size(); i++) 
        for (int j = 0; j < k; j++)
            dp[i][j] = 0;

    for (int i = 1; i <= G.size(); i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= 10 - G[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - 10 + G[i-1]] + H[i-1]);
            }
        }
    }
    return dp[G.size()][k];
}

int main(){
    int t, n, k;
    cin>>t;
    while (t--) {
        cin>>n>>k;
        for (int i = 0; i < n; i++) cin>>g[i];
        for (int i = 0; i < n; i++) {
            cin>>h[i];
            if (g[i] < 10) {
                G.pB(g[i]);
                H.pB(h[i]);
            }
        }
        k = min(k, maxk);
        cout<<solve(k)<<'\n';
        G.clear(); H.clear();
    }
    return 0;
}