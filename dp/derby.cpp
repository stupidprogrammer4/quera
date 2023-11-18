#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

const int maxn = 1e2+10;
int dp[maxn][maxn][2510], a[maxn];
char color[maxn];



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q, s = 0;
    cin>>n>>q;

    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    for (int i=2; i<=n; i++) {
        m = ceil((float)i/2.0f)*floor((float)i/2.0f);
        for (int j=0; j<=i; j++) {
            for (int k=0; k<=m; k++) {
                dp[i][j][k] = (dp[i-1][j-1][k] + dp[i-1][j][k-j]) % MOD;
            }
        }
    }
    bool change_color = false;


    int minx = 101;
    while (q--) {
        int t;
        cin>>t;
        if (t == 1) {
            int x;
            char c;
            cin>>x>>c;
            if (x == 1) {
                minx = 2;
            }
            else {
                minx = min(minx, x);
            }
            color[x] = c;
            change_color = true;
        }
        else if (t == 2) {
            int k1;
            cin>>k1;
            if (change_color) {
                dp[1][0][0] = color[1] != 'B' ? 1 : 0;
                dp[1][1][0] = color[1] != 'R' ? 1 : 0;
                for (int i=minx; i<=n; i++) {
                    m = ceil((float)i/2.0f)*floor((float)i/2.0f);
                    for (int j=0; j<=i; j++) {
                        for (int k=0; k<=m; k++) {
                            if (color[i] == 'R')
                                dp[i][j][k] = dp[i-1][j][k-j];
                            else if (color[i] == 'B') {
                                dp[i][j][k] = dp[i-1][j-1][k];
                            }
                            else {
                                dp[i][j][k] = (dp[i-1][j][k-j] + dp[i-1][j-1][k]) % MOD;
                            }
                        }
                    }
                }
            }
            int ans = 0;
            for (int j=0; j<=n; j++) {
                ans = (ans + dp[n][j][k1]) % MOD;
            }
            a[s++] = ans;
        }
    }

    for (int i=0; i<s; i++)
        cout<<a[i]<<'\n';


    // clock_t st = clock();
    
    // clock_t en = clock();

    // cout<<((double)en - (double)st) / CLOCKS_PER_SEC<<'\n';
}
