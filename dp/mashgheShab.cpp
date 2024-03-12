#include <bits/stdc++.h>

using namespace std;

#define int long long int 

const int maxn=5e3+10, mod=1e9+7;
int c[maxn][maxn], a[maxn], pre[maxn], suf[maxn];


int32_t main() {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    
    pre[0] = a[0], suf[n-1] = a[n-1];
    for (int i=1; i<n; i++) pre[i] = pre[i-1] + a[i];
    for (int i=n-2; i>=0; i--) suf[i] = suf[i+1] + a[i];
    
    for (int i=0; i<=n; i++)
        for (int j=0; j<=i; j++)
            if (j == 0 || i == 0)
                c[i][j] = 1;
            else 
                c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;

    int ans=0;
    for (int i=1; i<n; i++) {
        for (int j=2; j<=n; j++) {
            int len1 = j & 1 ? j/2+1 : j/2, len2 = j/2;
            int fix = (((c[i][len1]*c[n-i-1][len2-1])%mod)*a[i])%mod;
            int val = (((c[i][len1]*c[n-i >= 2 ? n-i-2 : n+1][len2 >= 2 ? len2-2 : n+1])%mod)*suf[i+1])%mod;
            int pos_sum = (fix+val)%mod, neg_sum = (((c[n-i-1][len2-1]*c[i-1][len1-1])%mod)*pre[i-1])%mod;
            if (!pos_sum || !neg_sum) break;
            int tmp = ((pos_sum - neg_sum)%mod+mod)%mod;
            ans = (ans+tmp)%mod;
        }
    }
    ans = ((ans-suf[0])%mod+mod)%mod;
    cout<<ans<<'\n';
}
