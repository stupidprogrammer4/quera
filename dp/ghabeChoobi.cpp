#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

const i64 maxn=65;
i64 a[maxn], c[maxn][maxn], dp[maxn][maxn][maxn];

i64 binary_search(int st, int en, int item) {
    while (st <= en) {
        i64 mid=(st+en)/2;
        if (a[mid] <= item)
            st = mid+1;
        else
            en = mid-1;
    }
    return st;
}

int main() {
    i64 n, K;
    cin>>n>>K;
    // pre process combination to get it later in O(1)
    for (i64 i=1; i<=60; i++) {
        for (i64 j=0; j<=i; j++) {
            if (j == 0 || i == j) {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    for (i64 i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);

    for (i64 i=1; i<=n; i++) 
        for (i64 j=1; j<=60; j++) 
            dp[i][j][1] = binary_search(0, i-1, j);
        
    for (i64 i=2; i<=n; i++) {
        for (i64 j=1; j<=60; j++) {
            for (i64 k=2; k<=i; k++) {
                dp[i][j][k] = dp[i-1][j][k];
                if (j >= a[i-1])
                    dp[i][j][k] += dp[i-1][j-a[i-1]][k-1];
            }
        }
    }
    i64 ans=0;
    for (i64 i=0; i<n; i++) {
        i64 t = c[i][K-1] - dp[i][a[i]][K-1];
        ans = ans + t;
    } 

    cout<<ans<<'\n';
}