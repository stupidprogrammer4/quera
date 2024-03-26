#include <bits/stdc++.h>

using namespace std;
#define int long long int

const int maxn=2e5+10, oo=1e15;
int a[maxn], dp1[maxn], dp2[maxn];

inline int MIN(int a, int b, int c) {
    return min(a, min(b, c));
}

inline int MIN(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}

int32_t main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;

        for (int i=0; i<n; i++) cin>>a[i];

        if (n == 1) {
            cout<<a[0]<<'\n';
            continue;
        }
        if (n == 2) {
            cout<<min(a[0], a[1])<<'\n';
            continue;
        } 

        dp1[0] = dp2[0] = dp2[1] = oo;
        dp1[1] = a[0];
        for (int i=2; i<=n; i++) {
            dp1[i] = MIN(dp2[i-1], dp1[i-1], dp2[i-2], dp1[i-2])+a[i-1];
            dp2[i] = dp1[i-1];
        }
        int ans0 = MIN(dp1[n], dp2[n], dp1[n-1], dp2[n-1]);
        dp2[1] = dp2[1] = oo;
        dp1[2] = a[1];
        for (int i=3; i<=n; i++) {
            dp1[i] = MIN(dp2[i-1], dp1[i-1], dp2[i-2], dp1[i-2])+a[i-1];
            dp2[i] = dp1[i-1];
        }
        int ans1 = MIN(dp1[n], dp2[n], dp1[n-1]);

        dp2[1] = dp1[0] = dp2[0] = 0;
        dp1[1] = oo;
        for (int i=2; i<=n; i++) {
            dp1[i] = MIN(dp2[i-1], dp1[i-1], dp2[i-2], dp1[i-2])+a[i-1];
            dp2[i] = dp1[i-1];
        }
        int ans2 = dp1[n];

        cout<<MIN(ans1, ans0, ans2)<<'\n';
    }
}