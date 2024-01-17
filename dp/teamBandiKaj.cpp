#include <bits/stdc++.h>

using namespace std;

#define MOD 1'000'007

const int maxn=1e4+10;
int a[maxn], dp[maxn][maxn], q[maxn];

int32_t main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i], q[i+1] = max(q[i], a[i]);

    for (int i=2; i<=n; i++) {
        dp[i][q[i-1]] = ((dp[i][q[i-1]] + a[i-1] - 1)+MOD)%MOD;
        for (int j=1; j<=i; j++) {
            int a=0;
            a = (1LL*j*dp[i-1][j]) % MOD;
            a = (a + dp[i-1][j-1]) % MOD;
            dp[i][j] = (dp[i][j] + a) % MOD;
        }
    }
    int ans=0;
    for (int i=0; i<=n; i++) ans = (ans+dp[n][i])%MOD;
    ans = (ans+1)%MOD;

    cout<<ans<<'\n';
}