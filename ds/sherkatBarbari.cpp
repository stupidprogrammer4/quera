#include <bits/stdc++.h>

using namespace std;

#define int long long int

const int maxn=1e5+10, INF=1e16;
int a[maxn], b[maxn], dp[maxn];
int p[4];

int cal(int a, int b) {
    if (a == b) return INF;
    return abs(a-b);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i]>>b[i];

    sort(a, a+n), sort(b, b+n);

    for (int i=1; i<=n; i++) {
        dp[i] = INF;
        for (int j=1; j<=3 && i-j>=0; j++) {
            for (int k=0; k<3; k++) p[k] = k;

            do {
                int cost=0;
                for (int k=0; k<j; k++)
                    cost += cal(a[i-1-k], b[i-1-p[k]]);
                dp[i] = min(dp[i], dp[i-j]+cost);
            } while (next_permutation(p, p+j));
        }
    }
    cout<<dp[n]<<'\n';
}
